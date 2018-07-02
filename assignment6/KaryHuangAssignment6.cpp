// Kary Huang Assignment #6
#include <iostream>
#include <iomanip>
using namespace std;

class HotelRoom 
{
private:
	int roomnum, capacity, occupancy;
	float roomrate;

public:
	HotelRoom(); 
	HotelRoom(int, int, float); 
	~HotelRoom(){ cout << "\nTHE END" << endl; }; //destructor
	void setOccupancy(int); //mutator
	int getRoomnum(); //accessor
	int getCapacity();
	int getOccupancy();
	float getRoomrate();
	void print(); //print function
	void changeRate(float);
	void changeStatus(int);
};

int main()
{
	int guests;
	HotelRoom room1(123, 4, 150.00); //invoke constructor version 2
	cout << "Hotel room number " << room1.getRoomnum() << " has a capacity of "
		<< room1.getCapacity() << " and " << room1.getOccupancy() << " guests. The room rate is "
		<< fixed << setprecision(2) << room1.getRoomrate() << "." << endl; 
	//another way to print to standard output besides using the print function

	cout << "Please enter number of guests: ";
	cin >> guests;
	room1.setOccupancy(guests); //assigns number of guests as occupancy
	room1.changeStatus(guests); 
	cout << "You entered: " << room1.getOccupancy() << " guests." << endl;
	while (guests > 4) //will not continue unless number of guests is within capacity limit
		{
			cout << "The number of guests has exceeded the room capacity. Please re-enter number of guests: ";
			cin >> guests;
			room1.setOccupancy(guests);
			room1.changeStatus(guests);
			cout << "You entered: " << room1.getOccupancy() << " guests." << endl;
		}
	room1.print();

	cout << "Did the guests check out? (Y or N) ";
	char answer;
	cin >> answer;
	while (answer != 'Y')
	{
		cout << "Did the guests check out? (Y or N) ";
		cin >> answer;
	}
	if (answer == 'Y') //only changes the status of the room when user confirms the check out
		room1.changeStatus(0); //changes the occupancy to 0
	room1.print();

	cout << "\nRoom Rate Update:" << endl;
	room1.changeRate(175.00); //changes the room rate to 175.00
	room1.print();
	cout << "Please enter number of guests: ";
	cin >> guests;
	room1.setOccupancy(guests);
	room1.changeStatus(guests);
	cout << "You entered: " << room1.getOccupancy() << " guests." << endl;
	while (guests > 4) //repeat the above process of asking the user to confirm number of guests
	{
		cout << "The number of guests has exceeded the room capacity. Please re-enter number of guests: ";
		cin >> guests;
		room1.setOccupancy(guests);
		room1.changeStatus(guests);
		cout << "You entered: " << room1.getOccupancy() << " guests." << endl;
	}
	room1.print();
	return 0;
}

HotelRoom::HotelRoom() //constructor version 1 - default values
{
	roomnum = 0;
	capacity = 0;
	occupancy = 0;
	roomrate = 89.00;
}
HotelRoom::HotelRoom(int a, int b, float c) //constructor version 2 - unknown values
{
	roomnum = a;
	capacity = b;
	occupancy = 0;
	roomrate = c;
}
void HotelRoom::setOccupancy(int occ)
{
	occupancy = occ;
}
int HotelRoom::getRoomnum()
{
	return roomnum;
}
int HotelRoom::getCapacity()
{
	return capacity;
}
int HotelRoom::getOccupancy()
{
	return occupancy;
}
float HotelRoom::getRoomrate()
{
	return roomrate;
}
void HotelRoom::print()
{
	cout << "Hotel room number " << roomnum << " has a capacity of " 
		<< capacity << " and " << occupancy << " guests. The room rate is " 
		<< fixed << setprecision(2) << roomrate << "." << endl;
}
void HotelRoom::changeRate(float new_rate)
{
	roomrate = new_rate;
}
void HotelRoom::changeStatus(int new_occupancy) //leaves occupancy as it is or assigns -1 to it if exceeds capacity
{
	if (occupancy > capacity)
		occupancy = -1;
	else occupancy = new_occupancy;
}
