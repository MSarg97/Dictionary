#ifndef PAYROLL_H
#define PAYROLL_H

#include <string>
#include <iostream>

//Payroll class with ID, name and city fields
class Payroll 
{
public:
	//Constructor
	Payroll(int num, std::string nm, std::string ct) 
	{
		ID = num;
		name = nm;
		city = ct;
	}

	//Functions for accessing private data members

	int getID() { return ID; }

	std::string getName() { return name; }
	
	std::string getCity() { return city; }

	//<< operator overloading function 
	friend std::ostream& operator<<(std::ostream& print, const Payroll *payrollPtr)
	{
		print << "ID: " << payrollPtr->ID << "\nName: " << payrollPtr->name << "\nCity: " << payrollPtr->city;
		return print;
	}

	~Payroll() {} // Destructor

private:
	int ID;
	std::string name;
	std::string city;

}; //End of Payroll class

#endif // !PAYROLL_H