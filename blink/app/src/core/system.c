#include "core/system.h"
#include <libopencm3/cm3/systick.h>
#include <libopencm3/cm3/vector.h>
#include <libopencm3/stm32/rcc.h>

static volatile uint32_t ticks = 0;

static void rcc_setup (void) {
	rcc_clock_setup_pll(&rcc_hsi_configs[RCC_CLOCK_3V3_84MHZ]);
}

void sys_tick_handler(void) {
	ticks++;
}

static void systick_setup(void){
    systick_set_frequency(SYSTICK_FREQ, CLOCK_SPEED);
	systick_counter_enable();
	systick_interrupt_enable();
}

uint32_t system_get_ticks(void){
	return ticks;
}

void system_init(void){
    rcc_setup();
    systick_setup();
}

void system_delay (uint32_t ms){
	uint32_t delay_end = system_get_ticks() + ms;
	while (system_get_ticks() < delay_end){
		// infinite spin
	}
}


