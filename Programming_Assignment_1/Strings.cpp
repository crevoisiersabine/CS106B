// This program will match a string to its Soundex code.

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;

int getSoundex(char character);

int main(){

	//Using the standard <string> and <fstream> libraries to read user input instead of using Stanford's library simpio.h
	int mistake;
	string input;
	string output;
	string name;
	while (true){
		stringstream converter;
		cout << "Enter surname (RETURN to quit): ";
		getline(cin, input);
		converter << input; //Push the input typed by the user to the stream
		//Check if user typed in some integers
		converter >> mistake;
		if(!converter.fail()){
			mistake = 1;
		}
		//Clear the stream in case it failed
		converter.clear();
		//Push back the input from the stream into a string output as this parses according to white spaces whereas getline did not
		converter >> output;
		if(!converter.fail()){
			//Check for any remaining characters left over once we got the string out, which should corresponds to the name
			char remaining;
			converter >> remaining;
			if(converter.fail() && mistake != 1){ // Couldn't read any more, so input is valid
 				if (input == "RETURN") { break; }
 				int Soundex = 0;
 				string SoundexString = output.substr(0, 1);
 				for (int j = 1; j < output.length(); j++){
 					Soundex = getSoundex(toupper(output[j]));
 					if (Soundex != 0 && Soundex != SoundexString[SoundexString.length() - 1] - 48){ //(-48) to convert character to int from ASCII encoding
 						SoundexString = SoundexString + to_string(Soundex);
 					}
 				}
 				if (SoundexString.length() == 4) {
 					cout << SoundexString << endl;
 				}
 				else if (SoundexString.length() < 4){
 					while(SoundexString.length() < 4){
 						SoundexString += "0";
 					}
 					cout << SoundexString << endl;
 				}
 				else {
 					cout << SoundexString.substr(0, 4) << endl;
 				}
 			}
 			else{
 				cout << "Please just enter a name. Try again !" << endl;
 			}
		}
	}
	return(0);
}


int getSoundex(char character){
	if (character == 'A' || character == 'E' || character == 'I' || character == 'O' || character == 'U' \
		|| character == 'H' || character == 'W' || character == 'Y'){
		return 0;
	}
	else if (character == 'B' || character == 'F' || character == 'P' || character == 'V'){
		return 1;
	}
	else if (character == 'C' || character == 'G' || character == 'J' || character == 'K' || character == 'Q' \
		|| character == 'S' || character == 'X' || character == 'Z'){
		return 2;
	}
	else if (character == 'D' || character == 'T'){
		return 3;
	}
	else if (character == 'M' || character == 'N'){
		return 4;
	}
	else if (character == 'L'){
		return 5;
	}
	else if (character == 'R'){
		return 6;
	}
	else{
		return 0;
	}
}


