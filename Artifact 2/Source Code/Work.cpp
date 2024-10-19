//This file provides all the working objects for the class FileToList

/*-----------------------PLANNING PHASE-------------------------------

For planner, will need separate file for schedules (course name, days, times(multiple entries, each with a different day or time(need a few same ones for proof of checking for day/time conflicts))

Planner needs to add courses to planner, check for day/time conflict, and needs to print out planner with course name, time, and date

*/    

#include<iostream>
#include<fstream>
#include<sstream>
#include<vector>
#include<string>
#include<algorithm>
#include<cctype>
#include"Stored.h"


using namespace std;


struct Course { // structure to hold classes
    string id;
    string title;
    string prereq1;
    string prereq2;
};

vector<Course> courses; // vector to hold classes


string toUpper(string str) { // uppercase function for user input for search function
    for (char& c : str) {
        c = toupper(c);
    }
    return str;
}



void FileToList::fileReader() { // reads file and stores it to a vector storing structures

    string filename = "courseList.txt"; // Replace with your file name
    ifstream inputFile(filename);

    if (!inputFile.is_open()) {
        std::cerr << "Error opening file: " << filename << endl;
    }

    string line;

    while (getline(inputFile, line)) {
        istringstream iss(line);
        Course course;

        getline(iss, course.id, ',');
        getline(iss, course.title, ',');
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

void FileToList::printCourseList() { // prints the courses from the vector courses
  
    for (const auto& c : courses) {
        cout << "ID: " << c.id << " | ";
        cout << "Title: " << c.title << endl;
    }
}

void FileToList::findCourse() { // finds course based on user input and prints out info on course. If invalid input, repeats loop.

    string user;
    bool found = false;
    
           
    cout << "What course would you like more information on?" << endl;
        
    while (!found) {
        cin >> user;
        
        for (const auto& c : courses) {


            user = toUpper(user);



            if (c.id == user) {
                cout << "ID: " << c.id << " | ";
                cout << "Title: " << c.title << " | ";
                cout << "Prerequisite 1: " << c.prereq1 << " | ";
                cout << "Prerequisite 2: " << c.prereq2 << endl;
                found = true;
                break;
            }
        }

        if (!found) {
            cout << "Invalid input, please try again!" << endl;
            cout << "What course would you like more information on?" << endl;
        }
    }
}

void FileToList::Menu() { // menu driving user interface interactions

    bool done = false;
    int choice;

    FileToList menuNav;


    cout << "Welcome to your course planner" << endl;
    cout << endl;
        
    
    while (!done) {
     
        cout << "Please see options below:" << endl;
        cout << endl;
        cout << "1. Load course data" << endl;
        cout << "2. print course list" << endl;
        cout << "3. Search for course" << endl;
        cout << "8. exit" << endl;
        cout << endl;
        cout << "Which would you like to do?" << endl;
        cout << endl;
                                                      //ADDED TRY/CATCH FOR INPUT VALIDATION
            cin >> choice;

            switch (choice) {

            case 1:

                menuNav.fileReader();
                cout << "File Loaded" << endl;
                cout << endl;
                break;

            case 2:

                menuNav.printCourseList();
                cout << endl;
                break;

            case 3:

                menuNav.findCourse();
                cout << endl;
                break;

            case 8:

                cout << "Thank you for using your course planner!" << endl;
                done = true;
                break;

            default:
                cout << "Invalid input, please try again" << endl;
                cout << endl;
            }
    }

}