#include <iostream>
#include <string>

#include "Payroll.h"
#include "ListDictionary.h"

using namespace std;

int main() 
{
	//IDDIctionary organizes Payroll records by ID
	ListDictionary <int, Payroll*> IDDictionary(4);

	//nameDictionary organizes Payroll records by name
	ListDictionary <string, Payroll*> nameDictionary(2);

	//Creating Payroll records
	Payroll *record1, *record2, *record3, *record4, *findRecord1, *findRecord2;

	record1 = new Payroll(5, "Joe", "London");
	record2 = new Payroll(10, "Andrew", "Los Angeles");
	record3 = new Payroll(15, "Kate", "Chicago");
	record4 = new Payroll(20, "Lucy", "Toronto");

	//Inserting records in IDDictionary and nameDictionary
	IDDictionary.insert(record1->getID(), record1);
	IDDictionary.insert(record2->getID(), record2);
	IDDictionary.insert(record3->getID(), record3);
	IDDictionary.insert(record4->getID(), record4);

	nameDictionary.insert(record1->getName(), record1);
	nameDictionary.insert(record2->getName(), record2);
	
	//Finding record with ID 10
	findRecord1 = IDDictionary.find(10);
	
	if (findRecord1 != nullptr)
		cout << "\nFound record with ID " << findRecord1->getID() << "\n\n" << findRecord1;
	else
		cout << "\n\nRecord not found\n";
	
	//Finding record with name Chris
	findRecord2 = nameDictionary.find("Chris");
	
	if (findRecord2 != nullptr)
		cout << "\nFound record with Name " << findRecord2->getName() << "\n\n";
	else
		cout << "\n\nRecord not found!\n";
		
	cout << "\nIDDictionary before removing the last item!\n\n";
	
	for (int i = 0; i < IDDictionary.size(); i++)
		cout << IDDictionary[i] << "\n\n";

	for (int k = 0; k < 10; k++)
	{
		cout << "IDDictionary after removing the last item!\n";

		IDDictionary.remove();

		if (!IDDictionary.size())
			cout << "Unable to remove the item! List is empty!\n\n";
		else
		{
			for (int i = 0; i < IDDictionary.size(); i++)
				cout << IDDictionary[i] << "\n\n";
		}							
	}
	
	delete record1;
	delete record2;
	delete record3;
	delete record4;

	return 0;
}
