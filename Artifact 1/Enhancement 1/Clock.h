/*James Nikolaou
10 / 18 / 2024
contact @ kmakers78@gmail.com
Version 1.2, final revision of original artifact

This 'Clock.h' file contains functions for setting the clocks and printing the clocks.
There are the 12 hour clock, 24 hour clock, and print clock function.

*/

#ifndef CLOCK
#define CLOCK

#include "Menu.h"

class Clock: public Menu {

public:

	void clock12(int hour12, int minute12, int sec12);
	void clock24(int hour24, int minute24, int sec24);
	void printClocks();

private:

};


#endif // !CLOCK

