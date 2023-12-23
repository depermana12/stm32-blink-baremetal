

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
	float duty_cycle = 0.0f;
	float max_duty_cycle = 100.0f;
	float min_duty_cycle = 0.0f;
	bool count_up = true;
	timer_pwm_set_duty_cycle(duty_cycle);
	
	while (1) {

    if (system_get_ticks() - start_time >= 10) {
		if (count_up) {
		duty_cycle += 1.0f;
		if (duty_cycle > max_duty_cycle){
			duty_cycle = max_duty_cycle;
			count_up = false;
		   } 
		} else {
			duty_cycle -= 1.0f;
			if (duty_cycle < min_duty_cycle){
			duty_cycle = min_duty_cycle;
			count_up = true;
		   } 
		}
      timer_pwm_set_duty_cycle(duty_cycle);	
	  start_time = system_get_ticks();
	}
	
	}
	// never return
	return 0;
}
