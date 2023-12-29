#include "core/system.h"
#include "core/gpio.h"
#include "core/timer.h"
#include "core/uart.h"


int main(void) {
	system_init();
	gpio_init();
	timer_init();
	uart_init();

    const char msg[] = "hello world\n";
	
	while (1) {

	

    uart_write(msg, sizeof(msg)/sizeof(msg[0]));
	system_delay(500);
	
	}
	// never return
	return 0;
}
