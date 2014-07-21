// This program will store entries in an address book

#include <iostream>
#include <string>
#include <set>
#include <locale>
using namespace std;

struct entryT {
 string firstName;
 string lastName;
 string phoneNumber;
};

entryT case_Insensitive(entryT a){
	for(int i = 0; i < a.lastName.length(); i ++){
		a.lastName[i] = tolower(a.lastName[i]);
	}
	for(int i = 0; i < a.firstName.length(); i ++){
		a.firstName[i] = tolower(a.firstName[i]);
	}
	return a;
}

//Function compare entries to the address book
int compare_Entries(entryT a, entryT b){
	if (case_Insensitive(a).lastName < case_Insensitive(b).lastName){
		return -1;
	}
	else if (case_Insensitive(a).lastName > case_Insensitive(b).lastName){
		return 1;
	}
	else {
		if (case_Insensitive(a).firstName < case_Insensitive(b).firstName) return -1;
		else if (case_Insensitive(a).firstName > case_Insensitive(b).firstName) return 1;
		else {
			if (a.phoneNumber == b.phoneNumber) return 0;
			else return 1;
		}
	}
}

/* Main function body */
int main() {

	// Set callback function mplemented as per Julie Zelenski's example using CS106B interface; as I am using standard c++ set, this doesn't work
	// set<entryT> AddressBook(compare_Entries);

	entryT one = { "Sabine", "Crevoisier", "0000000000" };
	entryT other = { "sabine", "crevoisier", "0000000000"} ;

	cout << compare_Entries(one, other) << endl;

	return 0;
}