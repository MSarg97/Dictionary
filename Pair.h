#ifndef PAIR_H
#define PAIR_H

#include <iostream>

//Pair class
template <typename Key, typename Value>
class Pair
{
public:
	Pair() = default; //Default constructor

	Pair(Key k, Value val) { key = k; value = val; } //Initializer constructor
	
	Pair(const Pair& p) { key = p.key; value = p.value; } //Copy constructor

	void operator=(const Pair& o) { key = o.key; value = o.value; } //Assignment operator

	Key getKey() { return key; }
	
	void setKey(Key k) { key = k; }
	
	Value getValue() { return value; }

private:
	Key key { };
	Value value { };

}; //End of Pair class

#endif // !PAIR_H
