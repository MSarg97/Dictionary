#ifndef ARRLIST_H
#define ARRLIST_H

#include <iostream>

//Array-based list implementation
template <typename T>
class ArrList
{
public:
	ArrList(int = 0); //Constructor

	void empty(); //Reinitialize the list

	void insert(const T&); //Insert the item at the current position

	void append(const T& item) { arrayList[listSize++] = item; }  //Append the item

	void remove(); //Remove the current item		

	void begin() { current = 0; } //Reset position

	void moveToEnd() { current = listSize; } //Move to end

	void previous() { if (current != 0) current--; } //Previous

	void next() { if (current < listSize) current++; } //Next

	int size() { return listSize; } //Return list size

	int currentPos() { return current; } //Return current position

	void moveToPos(int); //Set the list position to pos

	T& getItem(); //Return the current item

	T& getItemByIndex(int num); //Return the item with index num

	~ArrList() { delete[] arrayList; } //Destructor

private:
	int maxSize;
	int listSize;
	int current;
	T* arrayList;

}; //End of List class

template <typename T>
ArrList<T>::ArrList(int size)
{
	maxSize = size;
	listSize = current = 0;
	arrayList = new T[maxSize];
}

template <typename T>
void ArrList<T>::empty()
{
	delete[] arrayList;

	listSize = current = 0;
	arrayList = new T[maxSize];
}

template <typename T>
void ArrList<T>::insert(const T& item)
{
	if (listSize >= maxSize)
		std::cout << "Unable to insert the item!\n";
	else
	{
		for (int i = listSize; i > current; i--) //Shift elements to make a room for the item
			arrayList[i] = arrayList[i - 1];
		arrayList[current] = item;

		listSize++; //Increment list size
	}
}

template <typename T>
void ArrList<T>::remove()
{
	if (size() > 0)
	{
		for (int i = current; i < listSize - 1; i++) //Shift items right
			arrayList[i] = arrayList[i + 1];

		listSize--;
	}
}

template <typename T>
void ArrList<T>::moveToPos(int pos)
{
	if (pos < 0 && pos > maxSize)
		std::cout << "Position out of bound!\n";

	current = pos;
}

template <typename T>
T& ArrList<T>::getItem()
{
	if (current < 0 && current > listSize)
		std::cout << "Index out of bound!\n";

	return arrayList[current]; 
}

template <typename T>
T& ArrList<T>::getItemByIndex(int num)
{
	if (num < 0 && num > listSize)
		std::cout << "Index out of bound!\n";

	return arrayList[num];
}

#endif // !ARRLIST_H




