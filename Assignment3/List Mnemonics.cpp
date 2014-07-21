// This program finds all the possible combinations of letters corresponding to a given sequence of digits

#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <stdlib.h> //to convert string to integer using atoi
#include <typeinfo>
using namespace std;


map<int, string> Convert_digits(){

	map<int, string> characters_from_digit;
	string alphabet = "abcdefgh jklmnoprstuvwxy";
	//Special case for digit 1
	characters_from_digit.insert(make_pair(1, ""));
	for(int i = 2; i < 10; i++){
		characters_from_digit.insert(make_pair(i, alphabet.substr((i-2)*3, 3))); 
	}
	return characters_from_digit;
}

void Pick_from(string soFar, string rest) {
	if (soFar.length() == 3 || rest.length() < 3) {
 		cout << soFar << endl;
	} else {
		for (int j = 0; j < 3; j++){
			string remaining = rest.substr(0, j) + rest.substr(j+1);
			Pick_from(soFar + rest[j], rest.substr(3));
		}
	}
}

//Wrapper function
void ListMnemonics(string str){
	map<int, string> characters_from_digit = Convert_digits();
	string letters;
	int to_pick = str.length();
	for(int j = 0; j < str.length(); j++){
		for(map<int, string>::iterator itr = characters_from_digit.begin(); itr != characters_from_digit.end(); ++itr){
			if(itr->first == str.at(j) - 48){ //-48 to convert from a character to an integer
				letters += itr->second;
			}
 		}
	}
	Pick_from("", letters);
}

/* Main function body */
int main() {
	ListMnemonics("723"); 
	return 0;
}