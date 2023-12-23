#include <libopencm3/stm32/rcc.h>
#include "core/gpio.h"



static void gpio_setup(void){
	rcc_periph_clock_enable(RCC_GPIOA);
	rcc_periph_clock_enable(RCC_GPIOC);
	gpio_mode_setup(GPIO_PORTC, GPIO_MODE_OUTPUT, GPIO_PUPD_NONE, GPIO_PIN_13);
	gpio_mode_setup(GPIO_PORTA, GPIO_MODE_AF, GPIO_PUPD_NONE, GPIO_PIN_5);
	gpio_set_af(GPIO_PORTA, GPIO_AF1, GPIO_PIN_5);
}

void gpio_init(void){
    gpio_setup();
}
