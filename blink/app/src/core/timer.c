#include "core/timer.h"
#include <libopencm3/stm32/rcc.h>
#include <libopencm3/stm32/timer.h>

#define PRESCALER (8)
#define ARR_VALUE (8400)

static void timer_setup (void){
    rcc_periph_clock_enable(RCC_TIM2);
    timer_set_mode(TIM2, TIM_CR1_CKD_CK_INT, TIM_CR1_CMS_EDGE, TIM_CR1_DIR_UP);
    timer_set_oc_mode(TIM2, TIM_OC1, TIM_OCM_PWM1);
    timer_enable_oc_output(TIM2, TIM_OC1);
    timer_enable_break_main_output(TIM2);
    timer_set_prescaler(TIM2, PRESCALER - 1);
    timer_set_period(TIM2, ARR_VALUE - 1);
    timer_enable_counter(TIM2);


}

void timer_pwm_set_duty_cycle(float duty_cycle) {
  // duty cycle = (ccr / arr) * 100
  // duty cycle / 100 = ccr / arr
  // ccr = arr * (duty cycle / 100)
  const float raw_value = (float)ARR_VALUE * (duty_cycle / 100.0f);
  timer_set_oc_value(TIM2, TIM_OC1, (uint32_t)raw_value);
}

void timer_init (void){
    timer_setup();
}