/*James Nikolaou
10 / 18 / 2024
contact @ kmakers78@gmail.com
Version 1.2, final revision of original artifact

This 'Time.h' file contains functions for verifying user input for the clocks,
setting the time for the clocks, iterate the time for the clocks, and set the time hour.

*/

#ifndef TIME
#define TIME

#include "Menu.h"

class Time: public Menu {

public:

	void clockInputVerification();
	void setTime();
	void setTimeHour(int newHour);
	void iterateTime(int userInput);


private:

};


#endif // !TIME

