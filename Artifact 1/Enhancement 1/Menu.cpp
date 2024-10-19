/*James Nikolaou
10 / 18 / 2024
contact @ kmakers78@gmail.com
Version 1.2, final revision of original artifact

This 'Menu.cpp' file is the driving file of the program.

It contains all of the menus for the program and has functions
that allow interaction between the user and the program.

This file includes the intro menu and main menu for visability,
menu input verification, the user input menu for the user interaction within the program,
the menu input function that receives user input and does the work of the menu,
and the getter/setter methods for this program.

*/

#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>
#include "Menu.h"
#include "Time.h"
#include "Clock.h"
using namespace std;

//Global variables for this file
Menu menu;
Time timeFunction;
Clock clockFunction;

void Menu::intro() { //Intro message to prompt user to enter time

	cout << "***************************" << endl;
	cout << "*      Welcome User       *" << endl;
	cout << "*    Please Enter Time    *" << endl;
	cout << "***************************" << endl;
	cout << endl;
}

void Menu::mainMenu() { //User menu output to user


	cout << "***************************" << endl;
	cout << "*      Welcome User       *" << endl;
	cout << "*  Please Select Option:  *" << endl;
	cout << "*                         *" << endl;
	cout << "* 1 - Add One Hour        *" << endl;
	cout << "* 2 - Add One Minute      *" << endl;
	cout << "* 3 - Add One Second      *" << endl;
	cout << "* 4 - Set Time            *" << endl;
	cout << "* 5 - Print Clocks        *" << endl;
	cout << "* 6 - Exit Program        *" << endl;
	cout << "***************************" << endl;
	cout << endl;
}

int Menu::menuInputVerification() { //Verifies user input to ensure correct type and values

	

	while (true) {

		menu.mainMenu();
	
		// Try/catch method verifies correct input, and outputs an error for incorrect input
		try {

			string tempIn;
		
			cin >> tempIn;
			
			userInput = stoi(tempIn);

			if (userInput >= 1 && userInput <= 6) {

				break;
			}
			else {
				throw 505;
			}

		}

		catch (...) {

			cout << "INVALID INPUT, MUST BE 1,2,3,4,5,6" << endl;
			cout << endl;
		}

	}

	return userInput;
}


//Main menu utilized by user, provides navigation through various functions in program
void Menu::userInputMenu() {

	menu.menuInputVerification();
	
	userOption = userInput;

	while (true) {

		
		
		if (userOption == 1) { //Iterates Hours
			timeFunction.hour += 1;
			break;

		}
		else if (userOption == 2) { //Iterates Minutes, and adds a hour if minutes hit 60
			timeFunction.minute += 1;
			break;

		}
		else if (userOption == 3) { //Iterates seconds, and adds a second if seconds hit 60
			timeFunction.sec += 1;
			break;

		}
		
		else if (userOption == 4) { //Allows user to set time
			timeFunction.setTime();
			break;
		}

		else if (userOption == 5) { //Prints clocks
			clockFunction.printClocks();
			break;
		}

		else if (userOption == 6) { //Message for exiting program

			cout << "***************************" << endl;
			cout << "*    Exiting Program      *" << endl;
			cout << "*       Thank You         *" << endl;
			cout << "***************************" << endl;
			cout << endl;

			exit(0); //exits applicaton safely and successfully
		}
		else { //Message for invalid options

			cout << "***************************" << endl;
			cout << "*      Invalid Input      *" << endl;
			cout << "*  Please Use Valid Input *" << endl;
			cout << "***************************" << endl;
			cout << endl;
		}

		//Allows for values going over their clock standards to increment clock appropriately
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
}



void Menu::menuInput() { //Performs functions from user input based on their choices in the menu

	

	menu.intro();
	timeFunction.clockInputVerification();
	
	int mainHour = timeFunction.getHour();
	int mainMinute = timeFunction.getMinute();
	int mainSec = timeFunction.getSec();
	
	clockFunction.clock12(mainHour, mainMinute, mainSec);
	clockFunction.clock24(mainHour, mainMinute, mainSec);
	clockFunction.printClocks();

		while (true) {

			mainHour = timeFunction.getHour();
			mainMinute = timeFunction.getMinute();
			mainSec = timeFunction.getSec();

			clockFunction.clock12(mainHour, mainMinute, mainSec);
			clockFunction.clock24(mainHour, mainMinute, mainSec);

			menu.userInputMenu();


		}

}

 /*Below are getter/setter values so same values can be used across the entire program*/

int Menu::getHour() {

	return hour;

}
int Menu::getMinute() {

	return minute;

}
int Menu::getSec() {

	return sec;

}

void Menu::setHour(int newHour) {

	hour = newHour;

}
void Menu::setMinute(int newMinute) {

	minute = newMinute;

}
void Menu::setSec(int newSec) {

	sec = newSec;

}