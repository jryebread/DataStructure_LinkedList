#include <iostream>
#include <string>
#include "LinkedList.h"
using namespace std;
//Change "Data" to a Bank account Objects that encapsulate the data of a bank account user
//Use a class, add a tail possibly to keep track of end and head for front

//NOTES
//Doubly link list can traverse backwards
//Nodes simply hold data and have a pointer to another memory adress

int main()
{
	
	LL::LinkedList<int> nums;
	nums.addFront(1);
	nums.addFront(2);
	nums.addFront(3);
	nums.addFront(4);
	nums.printList();
	cout << "Empty: " << boolalpha << nums.isEmpty() << noboolalpha << endl;
	cout << "Size: " << nums.size() << endl << endl;
	return 0;
}
