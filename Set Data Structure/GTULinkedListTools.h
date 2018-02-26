#ifndef GTULinkedListTools_h
#define GTULinkedListTools_h
#include <iostream>
using std::shared_ptr;



namespace GTUContainers {
	template <class T>
	class Node {
	public:
		//CONSTRUCTOR
		Node(const T& theData, shared_ptr<Node<T> > theLink) :data(theData), link(theLink) {}
		//GETTERS
		shared_ptr<Node<T> > getLink() const { return link; }
		const T& getData() const { return data; }
		//SETTERS
		void setData(const T& theData) { data = theData; }
		void setLink(shared_ptr<Node<T> > pointer) { link = pointer; }
	private:
		T data;
		shared_ptr<Node<T> > link;
	};
	
	template <class T>
	class Iterator {
	public:
		//CONSTRUCTORS
		Iterator() : current(nullptr) {}
		Iterator(shared_ptr<Node<T> > initial) : current(initial) {}
		//Default copy constructor and assignment operator is working for this class.
		
		//ACCESS OPERATORS
		const T& operator *() const { return current->getData(); }
		const shared_ptr<Node<T> > operator ->() const { return current; }
		//INCREMENT OPERATORS
		Iterator& operator++() {
			current = current->getLink();
			return *this;
		}
		Iterator& operator++(int ignoreMe) {
			static Iterator temp(current); //To allocate space on heap for temp iterator object.
			current = current->getLink();
			return temp;
		}
		//COMPARASION OPERATORS
		bool operator ==(const Iterator& rtSide) const {
			return(current == rtSide.current);
		}
		bool operator !=(const Iterator& rtSide) const {
			return(current != rtSide.current);
		}
	private:
		shared_ptr<Node<T> > current;
	};
	
	/*
	 Inserts data from the head of the linked list, sets the new head.
	 */
	template <class T>
	void headInsert( shared_ptr<Node<T> > &head, const T& theData) {
		head = shared_ptr<Node<T> >(new Node<T>(theData,head));
	}
	/*------------------------------------------------------------*/
	
	/*
	 Inserts the given data after the given node, given node links to inserted data,
	 inserted data has the old nodes link to node after.
	 Useful for sorting when inserting new elements, but not used in this project.
	 */
	template <class T>
	void insert(shared_ptr<Node<T> > afterMe, const T& theData) {
		afterMe->setLink(new Node<T>(theData, afterMe->getLink()));
	}
	/*-----------------------------------------------------------------------*/
	
	/*
	 Deletes the node which given node points to, make a new link.
	 */
	template <class T>
	void deleteNode(shared_ptr<Node<T> > before) {
		shared_ptr<Node<T> > discard;
		discard = before->getLink();
		before->setLink(discard->getLink());
		discard = nullptr;
	}
	/*----------------------------------------------------------*/
	
	/*
	 Deteles the head node, sets the new head.
	 */
	template <class T>
	void deleteFirstNode(shared_ptr<Node<T> >& head) {
		shared_ptr<Node<T> > discard;
		discard = head;
		head = head->getLink();
		discard = nullptr;
	}
	/*-------------------------------------------*/
	
	
	/*
	 Linear search, returns the pointer to target if found, null otherwise.
	 */
	template <class T>
	shared_ptr<Node<T> > search(shared_ptr<Node<T> > head, const T& target) {
		shared_ptr<Node<T> > here;
		here = head;
		
		if (here == nullptr)//If empty list
			return nullptr;
		else {
			while (here->getData() != target && here->getLink() != nullptr)
				here = here->getLink();
			
			if (here->getData() == target)
				return here;
			
			else
				return nullptr;
		}
	}
	/*-------------------------------------------*/
	
	/*
	 Finds the node which points to the given target, used in erase since we only have forwards links
	 */
	template <class T>
	shared_ptr<Node<T> > findBefore(shared_ptr<Node<T> > head, const T& target) {
		shared_ptr<Node<T> > here;
		here = head;
		shared_ptr<Node<T> > next;
		next = head->getLink();
		
		if (here == nullptr)//If empty list
			return nullptr;
		else {
			while (next->getData() != target && next->getLink() != nullptr){
				here = here->getLink();
				if (here != nullptr)
					next = here->getLink();
			}
			if (next->getData() == target)
				return here;
			else
				return nullptr;
		}
	}
	/*----------------------------------------*/
	
}//End of tools
#endif //End of LinkedListTools.h
