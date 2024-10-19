/*James Nikolaou
10 / 18 / 2024
contact @ kmakers78@gmail.com
Version 1.2, final revision of original artifact

This 'Time.cpp' file contains functions for verifying user input for the clocks,
setting the time for the clocks, iterate the time for the clocks, and set the time hour.

*/

#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>
#include "Time.h"
#include "Menu.h"
#include "Clock.h"

using namespace std;

Menu menuTime;

Time timeTest;

void Time::clockInputVerification() { //Verifies user input to ensure correct type and values

	string tempHour;
	string tempMin;
	string tempSec;

	int hourTime = NULL;
	int minuteTime = NULL;
	int secTime = NULL;


	// Intakes user input and converts to string to buffer incorrect input.
	while (true) {

		// Utilizes try/catch method for errors. If incorrect input type, throws error and outputs message.
		try {
			
			cin >> tempHour;

			hourTime = stoi(tempHour);

			if (hourTime <= 24 && hourTime >= 0) {

				cin >> tempMin;

				minuteTime = stoi(tempMin);

				if (minuteTime <= 60 && minuteTime >= 0) {

					cin >> tempSec;

					secTime = stoi(tempSec);

					if (secTime <= 60 && secTime >= 0) {
						
						setHour(hourTime);
						setMinute(minuteTime);
						setSec(secTime);
						
						break;
					}
					else {
						throw 505;
					}
				}
				else {
					throw 505;
				}

			}
			else {
				throw 505;
			}

		}

		catch (...) {

			cout << "INVALID INPUT" << endl;
			cout << "Hour must be 0 - 24" << endl;
			cout << "Minute must be 0 - 60" << endl;
			cout << "Second must be 0 - 60" << endl;
		}

	}

}

//Sets time for clock
void Time::setTime() {

	cout << "Please set time" << endl;

	clockInputVerification();

	//return hour;
}

//Iterate time function
void Time::iterateTime(int iterate) {
	
	if (iterate == 1) { //Iterates Hours
		hour += 1;

	}
	else if (iterate == 2) { //Iterates Minutes, and adds a hour if minutes hit 60
		minute += 1;

	}
	else if (iterate == 3) { //Iterates seconds, and adds a second if seconds hit 60
		sec += 1;
	}

}

//Sets time hour
void Time::setTimeHour(int newHour) {

	setHour(newHour);
}