//Kary Huang Assignment 1
#include <iostream> 
#include <iomanip>
using namespace std;
int main()
{
	cout << "PART A" << endl;
	double a, p, r, n;
	p = 1000.00;
	r = 0.04;
	n = 5;
	a = p * pow((1 + r), n);
	cout << "The amount in the account at the end of 5 years is $" << a << '.' << "\n\n";
	cout << "PART B" << endl;
	n = 390;
	p = 24;
	a = p * pow((1 + r), n);
	cout << fixed << setprecision(2) << "The amount in the account today is worth $" << a << '.' << "\n\n";
	return 0;
}