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
		void addRoot(T value);
	public:
		LinkedList();
		bool isEmpty();
		unsigned size();
		void addFront(T value);
	};
#endif

	template<class T>
	void LinkedList<T>::addRoot(T value)
	{
		Node<T> *n = new Node<T>;
		n->data = value;
		n->next = nullptr;
		n->prev = nullptr;
		size++;
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
			addRoot(value);
		}
		else
		{
			n->next = Head;
			n->prev = nullptr;
			Head->prev = n;
			Head = n;
		}

	}
}