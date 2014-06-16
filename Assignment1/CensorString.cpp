/* This function takes two strings as input and returns the first string with all of the characters that are present
in the second removed. */

#include <iostream>
#include <string>
#include "simpio.h"
using namespace std;

/* Function prototype */

// string CensorString1(string originalText, string toBeRemoved);
void CensorString2(string &originalText, string toBeRemoved);

/* Main program */

int main() {
   string originalText = getLine("Please enter the first string: ");
   string toBeRemoved = getLine("Please enter the characters to remove as a string sequence: ");
   // string final = CensorString1(originalText, toBeRemoved);
   // cout << final << endl;
   CensorString2(originalText, toBeRemoved);
   cout << originalText <<endl;
   return 0;
}

/* Function definition - this one returns a string by creating a new string without the characters that we do not want */

// string CensorString1(string originalText, string toBeRemoved){

// 	for (int i = 0; i < toBeRemoved.length(); i++){
// 		// cout << originalText <<endl;
// 		int index = originalText.find(toBeRemoved.at(i), 0);
// 		// cout << toBeRemoved.at(i) << ", " << index <<endl;
// 		while (index != string::npos) {
// 			originalText = originalText.substr(0, index) + originalText.substr(index + 1);
// 			// cout << toBeRemoved.at(i) << ", " << index <<endl;
// 			index = originalText.find(toBeRemoved.at(i), 0);
// 		}
// 	}
// 	return originalText;
// }

/* Function definition - this one passes the string by reference and modifies it */

void CensorString2(string &originalText, string toBeRemoved){

	for (int i = 0; i < toBeRemoved.length(); i++){
		int index = originalText.find(toBeRemoved.at(i), 0);
		while (index != string::npos) {
			originalText.erase(index, 1);
			index = originalText.find(toBeRemoved.at(i), 0);
		}
	}
}