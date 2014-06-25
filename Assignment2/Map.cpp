#include <iostream>
#include <string>
#include <map>
#include <sstream>
#include <fstream>
using namespace std;

//Function prototype
char MostFrequentCharacter(ifstream &file_read, int &numOccurrences);

/* Main function body */
int main() {

	int numOccurrences = 0;

	//Ask user for file name until a correct one is given and open it, read it and put characters into a map
	ifstream file_read;
	while(true){
		string input;
		cout << "Enter file name: ";
		getline(cin, input);

		//Read the file in
		file_read.open(input);
		if (file_read.fail()){
			cout << "File didn't open! Please try again." << endl;
		}
		else{
			break;
		}
	}
	cout << MostFrequentCharacter(file_read, numOccurrences) << endl;		
	return 0;
}

char MostFrequentCharacter(ifstream &file_read, int &numOccurrences){

	string line;
	char letters;
	stringstream myStream;
	map<char, int> characterOccurrences;
	if (file_read.is_open()){
		while(getline(file_read, line)){
			//Push line into the stream as a string
			myStream << line;
			//Extract a character from the stream
			while(true){
				myStream >> letters;
				if(myStream.fail()){break;}
				if(characterOccurrences.find(letters) == characterOccurrences.end()){
					characterOccurrences.insert(make_pair(letters, 1));
				}
				else{
					characterOccurrences.at(letters) = characterOccurrences.at(letters) + 1;
				}
			}
			myStream.clear();
		}
	}

	char maxLetter = '\n';
	for(map<char, int>::iterator itr = characterOccurrences.begin(); itr != characterOccurrences.end(); ++itr)
 		if (itr->second > numOccurrences){
 			numOccurrences = itr->second;
 			maxLetter = itr->first;
 		}
	return maxLetter;
}


