#ifndef LISTDICTIONARY_H
#define LISTDICTIONARY_H

#include "ArrList.h"
#include "Pair.h"
#include "Dictionary.h"

#include <iostream>

//ListDictionary class derived from Dictionary abstract class
template <typename Key, typename Value>
class ListDictionary : Dictionary<Key, Value>
{
public:
	ListDictionary(int = 0); //Constructor

	void insert(const Key&, const Value&); //Insert an element

	void remove(); //Remove the last element

	Value find(const Key& k); //Find "k" using sequential search

	size_t size() { return list->size(); } //Return list size

	Value& operator[](int num); //Subscript operator overloading

	~ListDictionary() { delete list; } //Destructor

private:
	ArrList<Pair<Key, Value>>* list;

}; //End of ListDictionary class

template <typename Key, typename Value>
ListDictionary<Key, Value>::ListDictionary(int size)
{
	list = new ArrList<Pair<Key, Value>>(size);
}

template <typename Key, typename Value>
void ListDictionary<Key, Value>::insert(const Key& k, const Value& val) 
{
	Pair<Key, Value> temp(k, val);
	list->append(temp);
}
 
template <typename Key, typename Value>
void ListDictionary<Key, Value>::remove() 
{
	list->moveToEnd();
	list->previous();	
	list->remove();	
}

template <typename Key, typename Value>
Value ListDictionary<Key, Value>::find(const Key& k) 
{
	for (list->begin(); list->currentPos() < list->size(); list->next()) 
	{
		Pair<Key, Value> temp = list->getItem();

		if (k == temp.getKey())
			return temp.getValue();
	}

	return nullptr; //"k" does not appear in dictionary
}

template <typename Key, typename Value>
Value& ListDictionary<Key, Value>::operator[](int num)
{
	if (num < 0 && num > size())
		std::cout << "Index out of bound!\n";

	Pair<Key, Value> item = list->getItemByIndex(num);

	return item.getValue();
}
#endif // !LISTDICTIONARY_H
