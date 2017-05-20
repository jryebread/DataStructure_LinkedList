#include <iostream>
#include <string>
#include "LinkedList.h"
using namespace std;
//Change "Data" to a Bank account Objects that encapsulate the data of a bank account user
//Use a class, add a tail possibly to keep track of end and head for front

//NOTES
//Doubly link list can traverse backwards
//Nodes simply hold data and have a pointer to another memory adress

struct BankAccount
{
	int bankNum;
	double balance;
	string name;
};
int main()
{
	
	LL::LinkedList<BankAccount> accounts;
	BankAccount user;
	user.balance = 4000;
	user.bankNum = 1234;
	user.name = "Snowy";
	accounts.addFront(user);
	accounts.printList();
	cout << "Empty: " << boolalpha << accounts.isEmpty() << noboolalpha << endl;
	cout << "Size: " << accounts.size() << endl << endl;
	return 0;
}
