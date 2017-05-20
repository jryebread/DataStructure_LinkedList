#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <iostream>
//No CPP File because the templates mess stuff up apparently
//All definitions below class declaration
namespace LL 
{
	// struct NODE ====================//
	template <class T>
	struct Node {
		T data;
		//pointers
		Node<T> *next;
		Node<T> *prev;
		Node(T data)//initialize node with user data and set ptrs to null
			:data(data), next(nullptr), prev(nullptr) {};
	};

	// class ==========================//
	template <class T>
	class LinkedList {
	private:
		unsigned nodes;
		Node<T> *Head;
		Node<T> *Tail;
		//Helper functions
		Node<T> *getNode(T value);
		void addRoot(T value);
	public:
		void printList();
		void printRevList();
		LinkedList();
		bool isEmpty();
		Node<T> *begin();
		Node<T> *end();
		void popFront();
		void popBack();
		bool insertBefore(T currVal, T value);
		bool insertAfter(T currVal, T value);
		unsigned size();
		void addFront(T value);
		void addBack(T value);
	};
#endif

	/* class definitions ===============*/
	template<class T>
	LinkedList<T>::LinkedList()
	{
		nodes = 0;
		Head = nullptr;
		Tail = nullptr;
	}
	template<class T>
	void LinkedList<T>::printList()
	{
		//set a pointer to the head
		Node<T>*p = this->Head;
		//Traverse to the end of the list
		//printing values as we go
		while (p != nullptr)
		{
		cout << p->data << endl;
		p = p->next;
		}
		
	}
	template<class T>
	void LinkedList<T>::printRevList()
	{
		//Set a pointer to the tail
		Node<T>*p = this->Tail;
		//Traverse to the start of list while printing
		while (p != nullptr)
		{
			cout << p->data << endl;
			p = p->prev;
		}
	}
	template<class T>
	bool LinkedList<T>::isEmpty()
	{
		return nodes == 0;
	}

	template<class T>
	Node<T>* LinkedList<T>::begin()
	{
		Node<T> *p = Head;
		return p;
	}

	template<class T>
	Node<T>* LinkedList<T>::end()
	{
		Node<T>*p = Tail;
		return Tail;
	}
	template<class T>
	unsigned LinkedList<T>::size()
	{
		return nodes;
	}
	template<class T>
	void LinkedList<T>::addFront(T value)
	{
		if (isEmpty())
		{
			addRoot(value);
		}
		else
		{
			//Create a new node and set the data using node constructor
			Node<T> *n = new Node<T>(value);
			//point our new node's next ptr to the head
			n->next = Head;
			//attatch the next nodes previous to the new node
			n->next->prev = n;
			//point head to new node
			Head = n;
			nodes++;
		}

	}

	template<class T>
	void LinkedList<T>::addBack(T value)
	{
		if (isEmpty())
		{
			addRoot(value);
		}
		else
		{
			//Create a new node and set the data using node constructor
			Node<T> *n = new Node<T>(value);
			//set the nodes previous to point to tail
			n->prev = Tail;
			//attatch the previous node's next to the new node
			n->prev->next = n;
			//point tail to new node
			Tail = n;
			nodes++;
		}
	}
	template<class T>
	void LinkedList<T>::popFront() {
		if (!isEmpty()) {
			Node<T> *garbage = Head;
			if (nodes == 1) {
				Head = nullptr;
				Tail = nullptr;
			}
			else {
				Head = Head->next;
				Head->prev = nullptr;
			}
			delete garbage;
			nodes--;
		}
	}

	template<class T>
	void LinkedList<T>::popBack() {
		if (!isEmpty()) {
			Node<T> *garbage = Tail;
			if (nodes == 1) {
				Head = nullptr;
				Tail = nullptr;
			}
			else {
				Tail = Tail->prev;
				Tail->next = nullptr;
			}
			delete garbage;
			nodes--;
		}
	}
	template<class T>
	bool LinkedList<T>::insertBefore(T currVal, T value) {
		//find the node to insert before
		Node<T> *curr = getNode(currVal);
		if (curr != nullptr) {
			//create new new node
			Node<T> *n = new Node<T>(value);
			//attatch new node inbetween prev node and curr
			n->prev = curr->prev;
			n->next = curr;
			curr->prev->next = n;
			curr->prev = n;

			nodes++;
			return true;
		}
		return false;
	}
	template<class T>
	bool LinkedList<T>::insertAfter(T currVal, T value) {
		// find the node to insert after
		Node<T> *curr = getNode(currVal);
		if (curr != nullptr) {
			// create new new node
			Node<T> *n = new Node<T>(value);
			// attach new node inbetween curr and next node
			n->next = curr->next;
			n->prev = curr;
			curr->next->prev = n;
			curr->next = n;

			nodes++;
			return true;
		}
		return false;
	}

	/* Class helper function definitions =========================== */
	template<class T>
	void LinkedList<T>::addRoot(T value) {
		// create new node
		Head = new Node<T>(value);
		// create Tail
		Tail = Head;
		nodes++;
	}
	template<class T>
	Node<T> *LinkedList<T>::getNode(T value) {
		Node<T> *curr = Head;
		while (curr != nullptr) {
			if (curr->data == value)
				return curr;
			curr = curr->next;
		}
		return nullptr;
	}
}