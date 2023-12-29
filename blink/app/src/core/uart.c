#include <libopencm3/cm3/nvic.h>
#include <libopencm3/stm32/rcc.h>
#include <libopencm3/stm32/usart.h>
#include "core/uart.h"
#define BAUDRATE 115200

static void uart_config(void){
    rcc_periph_clock_enable(RCC_USART2);
    usart_set_baudrate(USART2, BAUDRATE);
    usart_set_databits(USART2, 8);
    usart_set_flow_control(USART2, USART_FLOWCONTROL_NONE);
    usart_set_mode(USART2, USART_MODE_TX);
    usart_set_parity(USART2, USART_PARITY_NONE);
    usart_set_stopbits(USART2, USART_STOPBITS_1);
    usart_enable_rx_interrupt(USART2);
    nvic_enable_irq(NVIC_USART2_IRQ);
    usart_enable(USART2);
}


void uart_write(const char* msg, uint16_t length) {
  for (uint16_t i = 0;i < length; i++){
    usart_send_blocking (USART2, msg[i]);
  }

}

void uart_init(void){
    uart_config();
}