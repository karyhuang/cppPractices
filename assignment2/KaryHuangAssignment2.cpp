//Kary Huang Assignment 2
#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	
	int empl_id, current_salary, salary_increase;
	int max_increase, max_employee, prev_salary;
	max_increase = 0;
	int x;
	for (int x = 1; x <= 10; x++)
	{
		cout << "Please enter your four digit employee ID: " << endl;
		cin >> empl_id;
		cout << "Please enter last year's salary: " << endl;
		cin >> prev_salary;
		cout << "Please enter this year's salary: " << endl;
		cin >> current_salary;
		salary_increase = current_salary - prev_salary;
		cout << "For employee ID " << empl_id << ',' << " salary has increased by $" << salary_increase << ", ";
		if (salary_increase > 5000)
			cout << "nice increase!" << endl << endl;
		else if (salary_increase >= 1000 && salary_increase <= 5000)
			cout << "fair increase!" << endl << endl;
		else if (salary_increase < 1000)
			cout << "small increase!" << endl << endl;
		if (salary_increase > max_increase)
		{
			max_increase = salary_increase;
			max_employee = empl_id;
		}

	}
	cout << "Employee with ID " << max_employee << " has the maximum increase in salary which is $" << max_increase << '.' << endl << endl;
	return 0;
}