/*James Nikolaou
10 / 18 / 2024
contact @ kmakers78@gmail.com
Version 1.2, final revision of original artifact

This 'stored' header file contains the structures used to store the course and planner information in the program.

It also contains the main class 'FileModify' which has all the functions to input/output data files,
and manipulate the vector data structures to utilize the course lookup features and the planner features.

*/

#ifndef Stored
#define Stored

#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
#include<vector>

using namespace std;

/* Structures below optimize data storage to allow for use of vectors running at O(N) time complexity */
struct Course { // structure to hold classes
		string id;
		string block;
		string title;
		string professor;
		string day;
		string time;
		string prereq1;
		string prereq2;
};

	/*added structure for planner information*/
struct Planner {
		string id;
		string block;
		string title;
		string professor;
		string day;
		string time;

		/*OVERLOAD FOR COMPARING TWO NOT EQUAL ITEMED STRUCTS*/

		bool operator==(const Planner& p) const {
			return ((id == p.id) && (block == p.block) && (title == p.title) && (professor == p.professor) && (day == p.day) && (time == p.time));
		}


};

class FileModify {

public:

	void fileReader(std::string fileName); //Reads in file
	void printCourseList(); //Prints out course list
	void findCourseByID(); //Finds course by ID/Block
	void findCourseByProfessor(); //Finds course by professor

	void Menu(); //Driving menu of program

	void fileFiller(string fileName); //Fills export file by writting out a txt file from planner vector data
	void plannerFiller(); //Fills planner with desired course
	void plannerReview(); //Prints out current planner vector

	

	void plannerUniqueAdd(string idVerify, string blockVerify, vector<Course>& course, vector<Planner>& planner); //Checks for uniqueness of classes entered into planner vector by ID/Block and Day/Time

	

private:




};

#endif
