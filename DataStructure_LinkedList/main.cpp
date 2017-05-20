#include <iostream>
#include <string>
#include "LinkedList.h"
using namespace std;

//NOTES
//Doubly link list can traverse backwards
//Nodes simply hold data and have a pointer to another memory adress

int main()
{

	LL::LinkedList<string> names;
	names.addBack("Snowy");
	names.addBack("Spot");
	names.addBack("Fluffy");
	names.addFront("Doggo");

	names.insertAfter("Spot", "James");
	names.printList();
	cout << "Size: " << names.size() << endl;
	cout << "___ReverseList___\n";
	names.printRevList();
	cout << "Size: " << names.size() << endl;
	cout << "___Popped front and back___" << endl;
	names.popBack();
	names.popFront();
	names.printList();
	cout << "Empty: " << boolalpha << names.isEmpty() << noboolalpha << endl;
	cout << "Size: " << names.size() << endl << endl;
	return 0;
}