/*James Nikolaou
10 / 18 / 2024
contact @ kmakers78@gmail.com
Version 1.2, final revision of original artifact

This 'Menu.h' file is the driving file of the program.

It contains all of the menus for the program and has functions
that allow interaction between the user and the program.

This file includes the intro menu and main menu for visability,
menu input verification, the user input menu for the user interaction within the program,
the menu input function that receives user input and does the work of the menu,
and the getter/setter methods for this program.

*/

#ifndef MENU
#define MENU


class Menu{

public:

	void intro();
	int menuInputVerification();
	void mainMenu();
	void userInputMenu();
	void menuInput();

	/*Below are getter/setter variables for usage of same 'hour', 'minute', 'second' across all classes*/

	//getter functions
	int getHour();
	int getMinute();
	int getSec();

	//setter functions
	void setHour(int newHour);
	void setMinute(int newMinute);
	void setSec(int newSec);

protected:

	// Main components of the clock
	int hour = 99;
	int minute = 99;
	int sec = 99;

	int userInput = NULL;
	int userOption = NULL;

	//int exit = 0;


};
#endif MENU
