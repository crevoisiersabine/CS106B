// This program returns a given string in reverse order.

#include <iostream>
#include <string>
using namespace std;

//Recursive
string ReverseString(string str){
	if(str.length() == 1){
		return str;
	}
	else{
		str = str[str.length()-1] + ReverseString(str.substr(0, str.length()-1));
		return str;
	}
}

//Non-recursive
string ReverseString_NR(string str){
	string new_string;
	for(int i = 0; i < str.length() + 1; i++){
		new_string += str[str.length()-i];
	}
	return new_string;
}

/* Main function body */
int main() {
	string word;
	cout << "Choose a word to substring: ? " << endl;
	cin >> word;
	cout << "Recursively, the reversed word is: " << ReverseString(word) << endl;
	cout << "Non recursively, the reversed word is: " << ReverseString_NR(word) << endl;
	return 0;
}