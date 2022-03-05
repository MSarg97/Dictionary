#ifndef DICTIONARY_H
#define DICTIONARY_H

//Dictionary abstract class
template <typename Key, typename Value>
class Dictionary
{
public:
	Dictionary() {} //Default constructor

	virtual void insert(const Key&, const Value&) = 0; //Insert a record

	virtual void remove() = 0; //Remove the last record
	
	virtual Value find(const Key&) = 0; //Find and return the record with specified key, if none exists, return nullptr
	
	virtual size_t size() = 0; //Return the number of records in the dictionary
	
	~Dictionary() {} //Base destructor

}; //End of Dictionary class

#endif // !DICTIONARY_H
