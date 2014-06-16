//This function counts the number of characters in a given file

#include <iostream>
#include <string>
#include <fstream>
#include "simpio.h"
#include "vector.h"
using namespace std;

//Initialise the prototype function for counting the characters
void CountLetters(string filename);

int main() {
	cout << "Enter file name: ";
	string filename = getLine();
	CountLetters(filename);
}

void CountLetters(string filename){
	Vector<char> characters;
	Vector<char> alphabet;
	string alphabet_string = "abcdefghijklmnopqrstuvwxyz";

	//Create the vector alphabet
	int position = 0;
	for(int j = 0; j < alphabet_string.length(); j++){
		alphabet.add(alphabet_string.at(position));
		position++;
	}

	//Read the file in
	ifstream file_read;
	file_read.open(filename.c_str());
	//Check if stream fails, if so, let the user know, and clear the stream so we can try again
	if (file_read.fail()){ 
		cout << "File didn't open!" << endl;
		exit(1);
	}

	//Create a vector of characters from the file
	string line;
	if (file_read.is_open()){
		while(getline(file_read, line)){
			int count = 0;
			for(int i = 0; i < line.length() ; i++){
				characters.add(line.at(count));
				count++;
			}
		}
	}

	//Count the number of letters
	for(int j = 0; j < alphabet.size(); j++){
		int count_letter = 0;
		for(int i = 0; i < characters.size(); i++){
			characters[i] = tolower(characters[i]);
			if (characters[i] == alphabet[j])
			{
				count_letter++;
			}
		}
		cout << alphabet[j] << ": " << count_letter << endl;
	}
}


