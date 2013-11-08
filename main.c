/*
 *  Low-power clock routine.  
 *  Works by sleeping, using watch-dog timer 
*/

#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/sleep.h>
#include <avr/wdt.h>
#include <avr/power.h>
// #include <util/delay.h>

#define DEBUG_LED     0

#define LED       PD7
#define LED_DDR   DDRD
#define LED_PORT  PORTD

#include "rtc.h"

ISR(WDT_vect){
	secondsTick();
}

int main(void) {
	wdt_enable(WDTO_1S); /* enable 1s watchdog */
	WDTCSR &= ~(1<<WDE); /* don't reset on watchdog*/
	sei();               /* enable global interrupts	*/
	set_sleep_mode(SLEEP_MODE_PWR_DOWN); // deepest sleep mode*/
	power_all_disable(); /* disable all peripherals.
   												only matters during brief awake periods, 
													but we're saving power here. */
#if DEBUG_LED
	LED_DDR |= (1<<LED) ;  /* enable LED output */ 
#endif
	while (1) {
		WDTCSR |= (1 << WDIE); /* re-enable watchdog interrupt
		                   (it's disabled each time it wakes up) */ 
		sleep_mode(); /* then to go sleep */ 
#if DEBUG_LED
		LED_PORT ^= (1<<LED);   /* enable LED output for diagnosis */	
#endif
	}                                                  /* End event loop */
  return (0);                            /* This line is never reached */
}
