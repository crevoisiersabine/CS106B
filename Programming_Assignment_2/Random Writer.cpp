//This program takes in some text and given a number for Markov order generates a random text up to 2000 characters of that order
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <sstream>
#include <fstream>
using namespace std;

//Initialise vector of characters from the input text
typedef vector<char> Vector_of_characters;

//Function prototypes
Vector_of_characters Read_file(Vector_of_characters &input_text);
int Markov_model();
map<string, vector<char> > Markov_text_analyser(Vector_of_characters &input_text, int model);

//Main function
int main(){
	//New vector
	Vector_of_characters input_text;
	Read_file(input_text);

	//Determine what Markov model to use - prompt the user to only choose an integer between 0 and 10
	int model;
	while(true){
		model = Markov_model();
		if(model < 11 && model >= 0){break; }
		else{cout << "Please choose an integer between 0 and 10" << endl;}
	}

	//Make a mapping of all occurrences of a particular sequence based on the Markov model chosen
	map<string, vector<char> > sequence_Map;
	sequence_Map = Markov_text_analyser(input_text, model);

	for(map<string, vector<char> >::iterator itr = sequence_Map.begin(); itr != sequence_Map.end(); ++itr){
 		cout << itr->first << endl;
 		for(vector<char>::iterator anotherITR = itr->second.begin(); anotherITR != itr->second.end(); ++anotherITR)
 			cout << *anotherITR << endl;
 	}

	return 0;
}
	
Vector_of_characters Read_file(Vector_of_characters &input_text){

	//Ask user for file name until a correct one is given and open it, read it and put scores into a vector
	while(true){
		string input;
		stringstream myStream;
		cout << "Enter file name: ";
		getline(cin, input);

		//Read the file in
		ifstream file_read;
		file_read.open(input);
		if (file_read.fail()){ 
			cout << "File didn't open! Please try again." << endl;
		}
		else{
			string line;
			while(getline(file_read, line)){
				//Push each line into the stream
				myStream << line;
				while(true){
					// Extract characters from the stream, character by character as well as white space
					char remaining;
					myStream >> noskipws >> remaining;
					input_text.push_back(remaining);
					if(myStream.fail()) {break; }
					myStream.clear();
				}
			}
			break;
		}
	}
	return input_text;
}

int Markov_model(){
	cout << "What order Markov model would you like to use (only between 0 and 10) ? " << endl;
	while(true){
		string input;
		stringstream myStream;
		getline(cin, input);
		int model;
		//Push into the stream what the user typed in
		myStream << input;
		//Extract an integer from the stream
		myStream >> model;
		if(!myStream.fail()){
			//Check if there are any leftover characters after integer has been extracted
			string remaining;
			myStream >> remaining; // Check for stray input
			if(myStream.fail()){ // Couldn't read any more, so input is valid
			 return model;
			}
			else{cout << "Unexpected character: " << remaining << endl;}
		}
		else{
			cout << "Please enter an integer!" << endl;
		}
		cout << "Retry: " << endl;
	}
}

map<string, vector<char> > Markov_text_analyser(Vector_of_characters &input_text, int model){

	vector<char> characters_that_follow;

	map<string, vector<char> > sequence_Map;
	for(int i = 0; i < input_text.size(); i++){
		string segment_key;
		for(int j = i; j < model+i; j++){
			segment_key += input_text[j];
		}
		if(sequence_Map.find(segment_key) == sequence_Map.end()){
			vector<char> characters_that_follow;
			characters_that_follow.push_back(input_text[i + model]);
			sequence_Map.insert(make_pair(segment_key, characters_that_follow));
		}
		else{
			characters_that_follow = sequence_Map.at(segment_key);
			characters_that_follow.push_back(input_text[i + model]);
			sequence_Map.at(segment_key) = characters_that_follow;
		}
	}
	return sequence_Map;
}


