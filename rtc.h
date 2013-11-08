
#include <avr/io.h>
// Clock-related globals
volatile uint8_t hours, minutes, seconds;
volatile uint16_t days, years;

// Run secondsTick once per second.
// When seconds reaches 60, secondsTick will call minutesTick()
// etc.  They cascade.

void secondsTick(void);
void minutesTick(void);
void hoursTick(void);
void daysTick(void);
