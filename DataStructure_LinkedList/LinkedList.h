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
	};

	/* class ==========================*/
	template <class T>
	class LinkedList {
	private:
		unsigned nodes;
		Node<T> *Head;
		Node<T> *Tail;
	public:
		void printList();
		LinkedList();
		bool isEmpty();
		unsigned size();
		void addFront(T value);
	};
#endif


	//The following function traverses forward to the end 
	//and then prints the list out in reverse order
	template<class T>
	void LinkedList<T>::printList()
	{
		//set a pointer to the head
		Node<T>*p = this->Head;
		//Traverse to the end of the list
		while (p->next != nullptr)
			p = p->next;
		//Use prev pointer to traverse backward
		//printing out values in reverse
		while (p != nullptr)
		{
			cout << p->data << endl;
			p = p->prev;
		}
	}

	/* class definition ===============*/
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
			Head = new Node<T>;
			Head->data = value;
			Head->next = nullptr;
			nodes++;
		}
		else
		{
			//Set a pointer equal to the head
			Node<T> *p = Head;
			//Traverse to the end of the list
			while (p->next != nullptr)
				p = p->next;
			//Create the new node
			Node<T>*n = new Node<T>;
			n->data = value;
			n->next = nullptr;
			nodes++;
			//LINK THE NODES
			n->prev = p;
			p->next = n;
		}

	}
}