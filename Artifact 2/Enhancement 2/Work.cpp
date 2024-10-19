/*James Nikolaou
10 / 18 / 2024
contact @ kmakers78@gmail.com
Version 1.2, final revision of original artifact

This 'work' file is the main driving file of the program. It contains all the working functions
within the program, the vectors for data storage, and the main menu driving the entire program.

The code contains all the functions relating towards the course search and planner tools.

The course search functions contain the file reader function to read in class list,
the print course list option to see all courses,
the search course by ID to get more information on a specific course, 
and the search by professor function to find classes taught by a particular professor.

The planner functions contain the unique search function which checks the planner vector
for unique courses based on ID and block (time's classes are offered), then by date and time to ensure no overlap.

It also contains the planner filler function that allows for storage within the planner vector,
it contains the file filler function which writes out the planner vector for portability of the data,
and it contains the planner review function that prints out the current planner vector.

The main menu is the driver of the file, allowing for the user to interact with the whole program and all its features.
*/
//This file provides all the working objects for the class FileToList


#include<iostream>
#include<fstream>
#include<sstream>
#include<vector>
#include<string>
#include<algorithm>
#include<cctype>
#include"Stored.h"


using namespace std;


/* Vector data structures containing the program's information */

vector<Course> courses; // vector to hold classes

vector<Planner> planner; // vector to hold planner info

/* Optimizes user input for reducing potential errors in input types */
string toUpper(string str) { // uppercase function for user input for search function
    for (char& c : str) {
        c = toupper(c);
    }
    return str;
}

/*---------------------------Course Search Portion of Code--------------------------*/

/* Algorithm created for reading in a designated file and stored in a vector data structure */
void FileModify::fileReader(string fileName) { // reads file and stores it to a vector storing structures

    string inFile = fileName; // Replace with your file name
    ifstream inputFile(inFile);

    if (!inputFile.is_open()) {
        std::cerr << "Error opening file: " << inFile << endl;
    }

    string line;

    while (getline(inputFile, line)) {
        istringstream iss(line);
        Course course;

        getline(iss, course.id, ',');
        getline(iss, course.block, ',');
        getline(iss, course.title, ',');
        getline(iss, course.professor, ',');
        getline(iss, course.day, ',');
        getline(iss, course.time, ',');
        getline(iss, course.prereq1, ',');
        getline(iss, course.prereq2);

        if (course.prereq1.empty()) {
            course.prereq1 = "none";
        }

        if (course.prereq2.empty()) {
            course.prereq2 = "none";
        }

        courses.push_back(course);
    }

    inputFile.close();
}

void FileModify::printCourseList() { // prints the courses from the vector courses data structure

    for (const auto& c : courses) {
        cout << "ID: " << c.id << " | ";
        cout << "Block: " << c.block << " | ";
        cout << "Title: " << c.title << endl;
    }
}

/* Algorithm to find a course by its ID and checks for unique block to ensure no overlap */
void FileModify::findCourseByID() { // finds course based on user input and prints out info on course. If invalid input, repeats loop.

    string userID;
    string userBlock;
    bool found = false;


    cout << "What course would you like more information on?" << endl;
    cout << "Please enter valid course ID for search" << endl;

    while (!found) { //While loop tries to iterate courses vector and if ID and block match user input, outputs full course information

        try {

            cin >> userID;

            for (const auto& c : courses) {


                userID = toUpper(userID);

                cout << "Which block would you like?" << endl;

                cin >> userBlock;

                userBlock = toUpper(userBlock);

                /* Double 'if' clauses allows for time complexity reduction by only performing function on a double match, then immediately breaks to reduce redundant searches*/

                if (c.id == userID) {
                    if (c.block == userBlock) {
                        cout << "ID: " << c.id << " | ";
                        cout << "Block: " << c.block << " | ";
                        cout << "Title: " << c.title << " | ";
                        cout << "Professor: " << c.professor << " | ";
                        cout << "Day: " << c.day << " | ";
                        cout << "Time: " << c.time << " | ";
                        cout << "Prerequisite 1: " << c.prereq1 << " | ";
                        cout << "Prerequisite 2: " << c.prereq2 << endl;
                        found = true;
                        break;
                    }
                    else {
                        break;
                    }
                }
                else {
                    break;
                }
            }

            if (!found) { // Output if course is not found, repeats loop
                cout << "Invalid input, please try again!" << endl;
                cout << "What course would you like more information on?" << endl;
            }
        }

        catch (...) {
            cout << "INVALID INPUT TYPE" << endl;
        }
    }
}

/* Algorithm to search for courses by professor */
void FileModify::findCourseByProfessor() { // finds course based on user input and prints out info on course. If invalid input, repeats loop.

    string user;
    bool found = false;


    cout << "Please enter professor's name" << endl;

    while (!found) { //While loop iterates through courses vector until it finds a unique match for professor name

        try {

            cin.ignore();
            getline(cin, user);

            for (const auto& c : courses) {


                user = toUpper(user);

                /* 'if' clause allows for time complexity reduction by only performing function on a  match, then immediately breaks to reduce redundant searches*/

                if (toUpper(c.professor) == user) {
                    cout << "ID: " << c.id << " | ";
                    cout << "Block: " << c.block << " | ";
                    cout << "Title: " << c.title << " | ";
                    cout << "Professor: " << c.professor << " | ";
                    cout << "Day: " << c.day << " | ";
                    cout << "Time: " << c.time << " | ";
                    cout << "Prerequisite 1: " << c.prereq1 << " | ";
                    cout << "Prerequisite 2: " << c.prereq2 << endl;
                    found = true;
                    break;
                }
            }

            if (!found) { // Output if professor is not found, repeats loop
                cout << "Could not find professor, please try again!" << endl;
            }
        }

        catch (...) {
            cout << "INVALID INPUT TYPE" << endl;
        }
    }
}

/*--------------------------PLANNER SECTION OF CODE---------------------------*/

/* Algorithm that checks for uniqueness of data being entered into planner vector based on ID and Block criteria.
* Also checks for uniqueness based on date and time.
*/
void FileModify::plannerUniqueAdd(string idVerify, string blockVerify, vector<Course>& course, vector<Planner>& plan) {

    for (const auto& c : course) {

        if (c.id == idVerify) {
            if (c.block == blockVerify) {

                Planner plannerHolder;
                plannerHolder.id = c.id;
                plannerHolder.block = c.block;
                plannerHolder.title = c.title;
                plannerHolder.professor = c.professor;
                plannerHolder.day = c.day;
                plannerHolder.time = c.time;

                /* For loop optimizes data structure storage by identifying if there is a repeat of a class based on ID/Block
                or a time conflict based on matching day/time already in vector */

                // Check if the mapped item from vector1 already exists in vector2
                bool exists = false;
                for (const auto& p : plan) {

                    if (plannerHolder.id == p.id && plannerHolder.block == p.block) {

                        cout << "Already in planner!" << endl;
                        exists = true;
                        break;
                    }

                    //Checks if time conflict
                    else if (plannerHolder.day == p.day && plannerHolder.time == p.time) {

                        cout << "Time Conflict!" << endl;
                        exists = true;
                        break;
                    }

                }

                // If the item does not exist in vector2, add it
                if (!exists) {

                    cout << "Added to planner" << endl;
                    plan.push_back(plannerHolder);

                }
            }
            else {

                break;
            }
        }
        else {
            break;
        }
    }

}

/* Algorithm for data storage in planner vector */
void FileModify::plannerFiller() { /*fills planner vector for manipulation*/


    bool done = false;
    while (!done) {

        try {
            cout << "What course would you like to add?" << endl;
            cout << "Please enter course ID" << endl;

            string userID;
            string userBlock;



            FileModify moveItems;

            cin.ignore();
            getline(cin, userID);
            userID = toUpper(userID);

            cout << "Which block would you like?" << endl;

            getline(cin, userBlock);
            userBlock = toUpper(userBlock);

            for (const auto& c : courses) {

                if (c.id == userID) {
                    if (c.block == userBlock) {

                        moveItems.plannerUniqueAdd(userID, userBlock, courses, planner);
                        done = true;
                        break;
                    }
                }

                else {
                    cout << "invalid input, please try again!" << endl;
                }

            }
        }

        catch(...) {
            cout << "ERROR:: INVALID DATA TYPE" << endl;
        }
    }

    for (const auto& p : planner) {
        cout << "ID: " << p.id << " | ";
        cout << "Block: " << p.block << " | ";
        cout << "Title: " << p.title << endl;
    }
}

/* Algorithm to export file from planner data vector */
void FileModify::fileFiller(string fileName) { /* Writes to export file*/

    bool done = false;

    while (!done) {

        
        ofstream outFS(fileName);

        if (outFS.is_open()) {

            for (const auto& p : planner) {

                outFS << p.id << p.block << p.title << p.professor << p.day << p.time << endl;
            }

            cout << "Export Successful!" << endl;

            done = true;
        }

        else {

            cout << "ERROR:: " << fileName << " NOT AVAILABLE" << endl;
            break;


        }

        

        outFS.close();
    }
}

/*prints planner*/
void FileModify::plannerReview() {

    for (const auto& p : planner) {
        cout << "ID: " << p.id << " | ";
        cout << "Title: " << p.title << endl;
    }
}








/* Main menu that drives program. This Algorithm takes in user input and provides solutions/results based on their desired input. */

void FileModify::Menu() { // menu driving user interface interactions

    bool done = false;
    string choice;          /*changed from int to string for buffer*/

    FileModify menuNav;


    cout << "Welcome to your course planner" << endl;
    cout << endl;


    while (!done) {

        cout << "Please see options below:" << endl;
        cout << endl;
        cout << "1. Load course data" << endl;
        cout << "2. print course list" << endl;
        cout << "3. Search for course" << endl;
        cout << "4. Search for professor" << endl;
        cout << "5. Fill planner" << endl;
        cout << "6. Review planner" << endl;
        cout << "7. Export planner" << endl;
        cout << "8. exit" << endl;
        cout << endl;
        cout << "Which would you like to do?" << endl;
        cout << endl;

        try {
            cin >> choice;

            switch (stoi(choice)) { /*converts string to int for switch*/

            case 1: //Reads in file

                menuNav.fileReader("courseList.txt");
                cout << "File Loaded" << endl;
                cout << endl;
                break;

            case 2: //Prints course list

                menuNav.printCourseList();
                cout << endl;
                break;

            case 3: //Finds course by ID and block

                menuNav.findCourseByID();
                cout << endl;
                break;

            case 4: //Finds course by professor

                menuNav.findCourseByProfessor();
                cout << endl;
                break;
            
            case 5: //Fills planner vector with desired courses

                menuNav.plannerFiller();
                cout << endl;
                break;

            case 6: //Prints current planner vector
                menuNav.plannerReview();
                cout << endl;
                break;

            case 7: //Exports planner vector by writing vector to a txt file

                menuNav.fileFiller("planner.txt");
                cout << endl;
                break;

            case 8: //Exit program

                cout << "Thank you for using your course planner!" << endl;
                done = true;
                break;

            default:
                cout << "Invalid input, please try again" << endl;
                cout << endl;
            }
        }

        catch (...) {

            cout << "INVALID INPUT, MUST BE 1,2,3,4,5,6,7,8" << endl;
            cout << endl;
        }

    }
}