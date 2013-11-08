#include "rtc.h"

void secondsTick(void){
	seconds++;
	if (seconds == 60){
		seconds = 0;
		minutesTick();
	}
}

void minutesTick(void){
	minutes++;
	if (minutes == 60){
		minutes = 0;
		hoursTick();
	}
}

void hoursTick(void){
	hours++;
	if (hours == 24){
		hours = 0;
		daysTick();
	}
}

void daysTick(void){
	days++;
	if (days == 365){
		days = 0;
		years++;
	}
}

