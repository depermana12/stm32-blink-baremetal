#include "core/timer.h"
#include <libopencm3/stm32/rcc.h>
#include <libopencm3/stm32/timer.h>

#define PRESCALLER (84)
#define ARR_VALUE (1000)

static void timer_setup (void){
    rcc_periph_clock_enable(RCC_TIM2);

    // high level timer configuration
    timer_set_mode(TIM2, TIM_CR1_CKD_CK_INT, TIM_CR1_CMS_EDGE, TIM_CR1_DIR_UP);

    // oc = output compare
    // setup PWM mode 
    timer_set_oc_mode(TIM2, TIM_OC1, TIM_OCM_PWM1);

    // enable PWM output
    timer_enable_counter(TIM2);
    timer_enable_oc_output(TIM2, TIM_OC1);

    // calculate the freq and resolution
    // rcc_clock is 84 MHz = 84_000_000
    // ARR auto_reload_register (period) 
    // freq = rcc_clock / ((prescaller - 1) * (ARR - 1))

    timer_set_prescaler(TIM2, PRESCALLER - 1);
    timer_set_period(TIM2, ARR_VALUE - 1);


}

void timer_pwm_set_duty_cycle(float duty_cycle){
    // duty cycle in percentage value
    // duty cycle = (ccr / arr) * 100
    // duty cycle / 100 = ccr / arr
    // ccr = arr * (duty cycle / 100)

    const float raw_value = (float) ARR_VALUE * (duty_cycle / 100.0f);
    timer_set_oc_value(TIM2, TIM_OC1, (uint32_t)raw_value);
}

void timer_init (void){
    timer_setup();
}