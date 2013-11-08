lowPowerClock
=============

A quick and dirty (approximate) low power clock routine for AVRs.

When just timing, it draws under 10 microamps, should last 5 years or longer on AAA batteries.

Also includes a bonus simple clock library that I end up using from time to time.  If you trigger
the secondsTick() function from a more accurate time source (like a calibrated oscillator) once
per second, the global variables and a couple functions take care of the rest.

You just need to add initializations for the clock (what time is it now?) and actually make it *do* something.


