#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>
using namespace std;

//Global variables for functions

int hour = 14;
int minute = 0;
int sec = 0;
int userOption = 0;
bool exitCheck = true;
string clock12 = "test";
string clock24 = "test";


void Clock12() { //Function to set 12 hour clock value
	
	string TOD = " AM";
	string hour1 = to_string(hour);
	string min1 = to_string(minute);
	string sec1 = to_string(sec);
	int tempHour;

	tempHour = hour;

	if (hour >= 12) {
		TOD = " PM";
	}
	if (hour > 12) {
		tempHour= hour - 12;
		hour1 = to_string(tempHour);
	}
	if (hour == 0) {
		tempHour = 12;
		hour1 = to_string(tempHour);
	}
	if (hour < 10) {
		hour1 = "0" + hour1;
		if (hour == 0) {
			tempHour = 12;
			hour1 = to_string(tempHour);
		}
	}
	if (minute < 10) {
		min1 = "0" + min1;
	}
	if (sec < 10) {
		sec1 = "0" + sec1;
	}
	
	clock12 = (hour1 + ":" + min1 + ":" + sec1 + TOD);
	
}

void Clock24() { //Function to set 24 hour clock value
	
	string hour2 = to_string(hour);
	string min2 = to_string(minute);
	string sec2 = to_string(sec);
	

	if (hour < 10) {
		hour2 = "0" + hour2;
	}
	if (minute < 10) {
		min2 = "0" + min2;
	}
	if (sec < 10) {
		sec2 = "0" + sec2;
	}

	clock24 = (hour2 + ":" + min2 + ":" + sec2);
}

void PrintClocks() { //Outprints clocks

	cout << "**************************			**************************" << endl;
	cout << "*     12-Hour Clock      *			*      24-Hour Clock     *" << endl;
	cout << "*      " << clock12 <<"       *		        *      "<< clock24 <<"          *" << endl;
	cout << "**************************			**************************" << endl;
	cout << endl;
}

void Intro() { //Intro message to prompt user to enter time

	cout << "***************************" << endl;
	cout << "*      Welcome User       *" << endl;
	cout << "*    Please Enter Time    *" << endl;
	cout << "***************************" << endl;
	cout << endl;
}

void SetTime() { //Sets time from user Input
	cin >> hour >> minute >> sec;
	
}

void UserMenu() { //User menu output to user


	cout << "***************************" << endl;
	cout << "*      Welcome User       *" << endl;
	cout << "*  Please Select Option:  *" << endl;
	cout << "*                         *" << endl;
	cout << "* 1 - Add One Hour        *" << endl;
	cout << "* 2 - Add One Minute      *" << endl;
	cout << "* 3 - Add One Second      *" << endl;
	cout << "* 4 - Exit Program        *" << endl;
	cout << "***************************" << endl;
	cout << endl;
}

void MenuInput() { //Performs functions from user input based on their choices in the menu
	cin >> userOption;

	if (userOption == 1) { //Iterates Hours
		hour += 1;
		
	}
	else if (userOption == 2) { //Iterates Minutes, and adds a hour if minutes hit 60
		minute += 1;
		
	}
	else if (userOption == 3) { //Iterates seconds, and adds a second if seconds hit 60
		sec += 1;
		
	}
	else if (userOption == 4) { //Message for exiting program
		
		cout << "***************************" << endl;
		cout << "*    Exiting Program      *" << endl;
		cout << "*       Thank You         *" << endl;
		cout << "***************************" << endl;
		cout << endl;
	}
	else { //Message for invalid options
		
		cout << "***************************" << endl;
		cout << "*      Invalid Input      *" << endl;
		cout << "*  Please Use Valid Input *" << endl;
		cout << "***************************" << endl;
		cout << endl;
	}
	if (sec >= 60) {
		sec -= 60;
		minute += 1;
	}
	if (minute >= 60) {
		minute -= 60;
		hour += 1;
	}
	if (hour >= 24) {
		hour = 0;
	}
}



int main() {

	Intro();
	SetTime();
	Clock12();
	Clock24();
	PrintClocks();

	while (exitCheck) {

		UserMenu();
		MenuInput();

		if (userOption == 4) {
			exitCheck = false;
			break;
		}
		Clock12();
		Clock24();
		PrintClocks();



	}
	return 0;
}