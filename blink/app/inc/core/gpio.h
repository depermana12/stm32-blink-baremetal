#include <libopencm3/stm32/gpio.h>

#define GPIO_PORT (GPIOA)
#define GPIO_PIN (GPIO5)
#define GPIO_PORTC (GPIOC)
#define GPIO_PIN_BLINK (GPIO13)

void gpio_init(void);