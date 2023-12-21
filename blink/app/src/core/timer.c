#include "core/timer.h"
#include <libopencm3/stm32/rcc.h>
#include <libopencm3/stm32/timer.h>

#define PRESCALLER (84)
#define ARR_VALUE (1000)

static void timer_setup (void){
    rcc_periph_clock_enable(RCC_TIM2);

    // high level timer configuration
    timer_set_mode(TIM2, TIM_CR1_CKD_CK_INT, TIM_CR1_CMS_CENTER_1, TIM_CR1_DIR_UP);

    // oc = output compare
    // setup PWM mode 
    timer_set_oc_mode(TIM2, TIM_OC1, TIM_OCM_PWM1);

    // enable PWM output
    timer_enable_oc_output(TIM2, TIM_OC1);

    timer_enable_break_main_output(TIM2);
    timer_set_oc_value(TIM2, TIM_OC1, 500);


    timer_set_period(TIM2, ARR_VALUE - 1);

    timer_enable_counter(TIM2);
}


void timer_init (void){
    timer_setup();
}