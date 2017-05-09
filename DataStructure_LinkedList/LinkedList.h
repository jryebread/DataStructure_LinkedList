#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <iostream>
namespace LL 
{
	/* struct NODE ====================*/
	template <class T>
	struct Node {
		T data;
		//pointers
		Node<T> *next;
		Node<T> *prev;
		Node(T data)//initialize node with user data and set ptrs to null
			:data(data), next(nullptr), prev(nullptr) {};
	};

	/* class ==========================*/
	template <class T>
	class LinkedList {
	private:
		unsigned nodes;
		Node<T> *Head;
		Node<T> *Tail;
		Node<T> *getNode(T value);
	public:
		void printList();
		LinkedList();
		bool isEmpty();
		bool insertBefore(T currVal, T value);
		bool insertAfter(T currVal, T value);
		unsigned size();
		void addRoot(T value);
		void addFront(T value);
		void addBack(T value);
	};
#endif

	/* class definition ===============*/
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
	LinkedList<T>::LinkedList()
	{
		nodes = 0;
		Head = nullptr;
		Tail = nullptr;
	}

	template<class T>
	bool LinkedList<T>::isEmpty()
	{
		return nodes == 0;
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
		// connect
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