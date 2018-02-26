#ifndef GTUSetBase_h
#define GTUSetBase_h
#include "GTULinkedListTools.h"

namespace GTUContainers{
	template <class T>
	class GTUSetBase {
	public:
		
		GTUSetBase() {};
		virtual ~GTUSetBase() {};
		
		//If set is empty returns true, false otherwise
		virtual bool empty() const = 0;
		
		//Returns size of the set in bytes
		virtual size_t size() const = 0;
		
		//Just a place holder, we have as musch space as heap for linked list
		virtual size_t max_size() const = 0;
		
		//Inserts element from the head
		virtual void insert(T item) = 0;
		
		//Deletes the matching data
		virtual void erase(const T& data) = 0;
		
		//Clears all contents of the set, makes it empty.
		virtual void clear() = 0;
		
		// Return number of occurance of the given key, maximum 1 for set because all elements are unique
		virtual int count(const T& wanted) const = 0;
		
		
		//Iterator<T> methods
		virtual Iterator<T> find(const T& data) const = 0; // Returns the iterator which points to given data
		virtual Iterator<T> begin() const = 0; //Sets iterator to head of the set
		virtual Iterator<T> end() const = 0; //Sets iterator to end of the set(nullptr)
		
		
		//MISC
		virtual bool contains(T target) const = 0;	//Return true if target is in the set
		virtual void output() = 0;					//Prints the set on screen
	};
}

#endif /* GTUSetBase_h */
