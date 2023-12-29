#include <libopencm3/stm32/rcc.h>
#include "core/gpio.h"

static void gpio_setup(void){
	rcc_periph_clock_enable(RCC_GPIOA);

	gpio_mode_setup(GPIO_PORTA, GPIO_MODE_AF, GPIO_PUPD_NONE, GPIO_PIN_2);
	gpio_set_af(GPIO_PORTA, GPIO_AF7, GPIO_PIN_2);
}

void gpio_init(void){
    gpio_setup();
}
