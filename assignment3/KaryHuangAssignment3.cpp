//Kary Huang Assignment 3 with EC#1
#include <iostream>
#include <cmath>
#include <fstream>
#include <iomanip>
using namespace std;
int main()
{
	ifstream a3in("C:\\Users\\kary\\Desktop\\CIS3100\\KaryHuangAssignment3Edited\\a3in.txt");
	ofstream a3eout("a3eout.out");
	a3eout << "Employee ID" << setw(3) << " " << "Previous Salary" << setw(3) << " " << "Current Salary"
		<< setw(3) << " " << "Increase" << setw(3) << " " << "Comment" << endl;
	int empl_id, prev_salary, current_salary, salary_increase, count = 0;
	float total_increase = 0.0, avg_increase;
	cout << "Please enter your four digit employee ID, previous and current salary: " << endl;
	while (a3in >> empl_id)
	{
			a3in >> prev_salary;
			a3in >> current_salary;
			a3eout << empl_id << setw(10) << " " << prev_salary << setw(14) << " " << current_salary << setw(13) << " ";
			salary_increase = current_salary - prev_salary;
			a3eout << salary_increase << setw(7) << " ";
			if (salary_increase > 5000)
				a3eout << "Nice increase" << endl;
			else if (salary_increase >= 1000 && salary_increase <= 5000)
				a3eout << "Fair increase" << endl;
			else if (salary_increase < 1000)
				a3eout << "Small increase" << endl;
			count++;
			total_increase = total_increase + salary_increase;
			cout << "\nPlease enter your four digit employee ID, previous and current salary: " << endl;
	}
	avg_increase = total_increase / count;
	a3eout << "\nThe number of employees processed is " << count << "." << endl;
	a3eout << "The average increase is " << avg_increase << "." << endl;
	a3eout.close();
	a3in.close();
	return 0;
}