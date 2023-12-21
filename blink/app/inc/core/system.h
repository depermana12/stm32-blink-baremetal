#include "common-defines.h"

#define SYSTICK_FREQ (1000)
#define CLOCK_SPEED (84000000)

uint32_t system_get_ticks(void);
void system_init(void);
void system_delay (uint32_t ms);