//Kary Huang Assignment #4 version 2 (different ways of writing the two functions)
#include <iostream>
#include <cmath>
#include <fstream>
#include <iomanip>
using namespace std;

float findavg(int, int, int, int); //prototype for the average function
char lettergrade(float, char&); //prototype for the letter grade conversion function

int main()
{
	ifstream a4in("C:\\Users\\kary\\Desktop\\CIS3100\\KaryHuangAssignment4\\a4in.txt");
	ofstream a4out2("a4out2.txt");
	char grade = 'A'; //initialize the variable 
	int student_id, grade1, grade2, grade3, grade4, count = 0;
	float average;
	while (a4in >> student_id) //reads the first value from the input file, then perform the following
	{
		a4in >> grade1 >> grade2 >> grade3 >> grade4;
		a4out2 << "The student with ID " << student_id << " has grades " << grade1 << " " << grade2 << " " << grade3 << " " << grade4 << endl;
		average = findavg(grade1, grade2, grade3, grade4); //set the result of the average function to the variable average
		a4out2 << "The average is " << fixed << setprecision(2) << average << endl; //format the average to 2 decimal places
		lettergrade(average, grade); //call the letter grade conversion function
		a4out2 << "The grade is " << grade << endl << endl;
		count++;
	}
	a4out2 << "\nThe number of students processed was " << count << "." << endl;
	a4in.close();
	a4out2.close();
	return 0;
}

float findavg(int a, int b, int c, int d) //the average function
{
	return (a + b + c + d) / 4.0;
}

char lettergrade(float x, char& letter) //the letter grade conversion function
{
	if (x >= 90)
		letter = 'A';
	else if (x >= 80)
		letter = 'B';
	else if (x >= 70)
		letter = 'C';
	else if (x >= 60)
		letter = 'D';
	else letter = 'F';
	return letter;
}