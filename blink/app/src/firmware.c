#include "core/system.h"
#include "core/gpio.h"
#include "core/timer.h"

#define FADE_STEP (10)
#define LED_DELAY (300)

int main(void) {
	system_init();
	gpio_init();
	timer_init();

	uint32_t start_time = system_get_ticks();
	uint32_t blink_time = system_get_ticks();
	float duty_cycle = 0.0f;

	timer_pwm_set_duty_cycle(duty_cycle);
	
	while (1) {
		if (system_get_ticks() - start_time >= FADE_STEP){
			duty_cycle += 1.0f;
			if (duty_cycle > 100.0f) {
               duty_cycle = 0.0f;
            } 
			timer_pwm_set_duty_cycle(duty_cycle);
			start_time = system_get_ticks();
		}

		// the use of below prototype is non-blocking delay
		// its check time 
		if (system_get_ticks() -  blink_time >= LED_DELAY){
			gpio_toggle(GPIO_PORTC, GPIO_PIN_BLINK);
			blink_time = system_get_ticks();
		}
		    // this code is blocking delay
			// it wait until the delay time reach
			//gpio_toggle(GPIO_PORTC, GPIO_PIN_BLINK);
			//system_delay (100);

	}
	// never return
	return 0;
}
