/*James Nikolaou
10 / 18 / 2024
contact @ kmakers78@gmail.com
Version 1.2, final revision of original artifact

This 'Clock.cpp' file contains functions for setting the clocks and printing the clocks.
There are the 12 hour clock, 24 hour clock, and print clock function.

*/

#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>
#include "Clock.h"
#include "Menu.h"
#include "Time.h"
using namespace std;

//Global variables for file


string clock12Output = "test";
string clock24Output = "test";

Menu menuClock;
Time timeClock;


void Clock::clock12(int hour12, int minute12, int sec12) { //Function to set 12 hour clock value

	int tempHour = hour12;
	int clockHour = hour12;
	int clockMinute = minute12;
	int clockSec = sec12;
	
	string TOD = " AM";
	string hour1 = to_string(clockHour);
	string min1 = to_string(clockMinute);
	string sec1 = to_string(clockSec);
	

	// For the 12 hour clock, it checks if the value needs to be AM or PM
	// by checking if the value is greater than 12 or not. 
	if (clockHour >= 12) {
		TOD = " PM";
	}

	// If value is greater than 12 it subtracts 12 to keep 12 hour clock format

	if (clockHour > 12) {
		tempHour = clockHour - 12;
		hour1 = to_string(tempHour);
	}

	// Sets a 0 value to 12 for 12 hour clock format
	if (clockHour == 0) {
		tempHour = 12;
		hour1 = to_string(tempHour);
	}

	// The below methods allow for keeping a 2-digit format by if the value being less
	// than 10 it provides a 0 in front.
	if (clockHour < 10) {
		hour1 = "0" + hour1;
		if (clockHour == 0) {
			tempHour = 12;
			hour1 = to_string(tempHour);
		}
	}
	if (clockMinute < 10) {
		min1 = "0" + min1;
	}
	if (clockSec < 10) {
		sec1 = "0" + sec1;
	}

	//prints clock
	clock12Output = (hour1 + ":" + min1 + ":" + sec1 + TOD);

}

void Clock::clock24(int hour24, int minute24, int sec24) { //Function to set 24 hour clock value

	int clockHour = hour24;
	int clockMinute = minute24;
	int clockSec = sec24;
	
	string hour2 = to_string(clockHour);
	string min2 = to_string(clockMinute);
	string sec2 = to_string(clockSec);

	

	// The below methods allow for keeping a 2-digit format by if the value being less
	// than 10 it provides a 0 in front.
	if (clockHour < 10) {
		hour2 = "0" + hour2;
	}
	if (clockMinute < 10) {
		min2 = "0" + min2;
	}
	if (clockSec < 10) {
		sec2 = "0" + sec2;
	}

	//prints clock
	clock24Output = (hour2 + ":" + min2 + ":" + sec2);
}

void Clock::printClocks() { //Outprints clocks

	cout << "**************************			**************************" << endl;
	cout << "*     12-Hour Clock      *			*      24-Hour Clock     *" << endl;
	cout << "*      " << clock12Output << "       *		        *      " << clock24Output << "          *" << endl;
	cout << "**************************			**************************" << endl;
	cout << endl;
}
