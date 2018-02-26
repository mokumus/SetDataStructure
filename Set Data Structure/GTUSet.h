#ifndef GTUSet_h
#define GTUSet_h
#include<iostream>
#include "GTULinkedListTools.h"
#include "GTUSetBase.h"
using std::cout;
using std::endl;

namespace GTUContainers{
	template <class T>
	class GTUSet  : public GTUSetBase<T>{
	public:
		GTUSet() : head(nullptr) {};
		virtual ~GTUSet();
		
		/*Wanted Methods*/
		bool empty() const;
		size_t size() const;
		size_t max_size() const { return 10 * size(); }
		void insert(T item);
		void erase(const T& data);
		void clear();
		int count(const T& wanted) const;
		Iterator<T> find(const T& data) const;
		Iterator<T> begin() const { return Iterator<T>(head); }
		Iterator<T> end() const { return Iterator<T>(); }
		/*-----------------*/
		
		//MISC
		bool contains(T target) const;	//Return true if target is in the set
		void output();					//Prints the set on screen
		
	protected:
		shared_ptr<Node<T> > head;
	};
	
	/*
	 Deletes nodes starting from head until a link is nullptr
	 */
	template <class T>
	GTUSet<T>::~GTUSet() {
		shared_ptr<Node<T>> toDelete;
		toDelete = head;
		while (head != nullptr) {
			head = head->getLink();
		//	delete toDelete;
			toDelete = head;
			
		}
	}
	/*---------------------------------*/
	
	template <class T>
	bool GTUSet<T>::empty() const{
		if(head == nullptr)
			return true;
		else
			return false;
	}
	
	
	
	template <class T>
	bool GTUSet<T>::contains(T target) const {
		shared_ptr<Node<T>> result = search(head, target);
		if (result == nullptr)
			return false;
		else
			return true;
	}
	
	template <class T>
	void GTUSet<T>::output() {
		cout << "[";
		for (auto i = this->begin(); i != this->end(); i++)
			cout << i->getData() << ", ";
		
		cout << "]";
		
		
		cout << endl;
	}
	
	template <class T>
	void GTUSet<T>::insert(T item) {
		if (search(head, item) == nullptr)
			headInsert(head, item);
		else
			throw -1;
		
	}
	
	template <class T>
	void GTUSet<T>::clear() {
		for (auto i = this->begin(); i != this->end(); i++) {
			if (i->getLink() != nullptr)
				deleteFirstNode(head);
		}
		deleteFirstNode(head);
	}
	
	template <class T>
	void GTUSet<T>::erase(const T& data) {
		auto temp = findBefore(head, data);
		
		if (head->getData() == data)
			deleteFirstNode(head);
		
		else if (temp != nullptr)
			deleteNode(temp);
		
		else
			cout << "Not found" << endl;
	}
	
	template <class T>
	Iterator<T> GTUSet<T>::find(const T& data) const {
		return search(head, data);
	}
	
	template <class T>
	size_t GTUSet<T>::size() const {
		auto size = sizeof(T&);
		for (auto i = this->begin(); i != this->end(); ++i)
			size++;
		
		return size;
	}
	
	template <class T>
	int GTUSet<T>::count(const T& wanted) const {
		int matches = 0;
		
		for (auto i = this->begin(); i != this->end(); i++) {
			
			if (i->getData() == wanted)
				matches++;
		}
		return matches;
	}
}
#endif /* GTUSet_h */
