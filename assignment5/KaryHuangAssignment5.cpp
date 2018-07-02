//Kary Huang Assignment #5
#include <iostream>
#include <cmath>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;

float final_grade(float[], int[]); //prototype for the student average function

int main()
{
	ifstream a5in("C:\\Users\\kary\\Desktop\\CIS3100\\KaryHuangAssignment5\\a5in.txt");
	ofstream a5out("a5out.txt");
	string student_first, student_last, max_first, max_last, min_first, min_last;
	float weights[4]; //the array for weights
	int grade[8]; //the array for grades
	int i, j, x, student_id;
	float min = 100.0, max = 0.0, student_avg, sum = 0.0;
	a5out << "First Name" << setw(3) << " " << "Last Name" << setw(3) << " " << "Student ID" << setw(3) << " " << "Final Grade" << endl; //column headings
	for (i = 0; i < 4; i++) //read in weights into first array
		{
			a5in >> weights[i];
		}
	
	for (x = 1; x <= 15; x++) //read in 15 sets of student record
	{
		while (a5in >> student_first) //if there is a student first name, then perform the following
		{
		a5in >> student_last;
		a5in >> student_id;
		a5out << left << setw(13) << student_first << setw(12) << student_last << setw(13) << student_id;
			for (j = 0; j < 4; j++) //read in grades into second array one student at a time
			{
				a5in >> grade[j];
			}
			student_avg = final_grade(weights, grade); //call the student average function
			a5out << student_avg << endl;
			sum = sum + student_avg;
			if (student_avg > max)
			{
				max = student_avg;
				max_first = student_first;
				max_last = student_last;
			}
			if (student_avg < min)
			{
				min = student_avg;
				min_first = student_first;
				min_last = student_last;
			}
		}
	}

	a5out << "\nLowest grade in class: " << min_first << " " << min_last << " " << min << endl;
	a5out << "Highest grade in class: " << max_first << " " << max_last << " " << max << endl;
	a5out << "Class average: " << fixed << setprecision(2) << sum / 15.0 << endl;
	a5in.close();
	a5out.close();
	return 0;
}

float final_grade(float weights[], int grade[]) //the student average function
{
	int k = 0;
	return (weights[0] * grade[k] + weights[1] * grade[k + 1] + weights[2] * grade[k + 2] + weights[3] * grade[k + 3]);
}

