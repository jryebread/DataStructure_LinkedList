#include <iostream>
#include <string>
#include "LinkedList.h"
using namespace std;
//Change "Data" to a Bank account Objects that encapsulate the data of a bank account user
//Use a class, add a tail possibly to keep track of end and head for front

//NOTES
//Doubly link list can traverse backwards
//Nodes simply hold data

int main()
{
	LL::LinkedList<int> nums;
	cout << "Empty: " << boolalpha << nums.isEmpty() << noboolalpha << endl;
	cout << "Size: " << nums.size() << endl << endl;
	return 0;
}
