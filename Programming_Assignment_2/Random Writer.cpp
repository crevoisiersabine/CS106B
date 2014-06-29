//This program takes in some text and given a number for Markov order generates a random text up to 2000 characters of that order
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <sstream>
#include <fstream>
#include <cstdlib> //to use random function
using namespace std;

//Initialise vector of characters from the input text
typedef vector<char> Vector_of_characters;

//Function prototypes
Vector_of_characters Read_file(Vector_of_characters &input_text);
int Markov_model();
map<string, vector<char> > Markov_text_analyser(Vector_of_characters &input_text, int model);
void Print_random_sequence(map<string, vector<char> > sequence_Map, int model);
double RandomChance(int size);

//Main function
int main(){

	/* Seed the randomizer. The static_cast converts the result of time(NULL) from
 * time_t to the unsigned int required by srand. This line is idiomatic C++.
 */
 	srand(static_cast<unsigned int>(time(NULL)));

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
	Print_random_sequence(Markov_text_analyser(input_text, model), model);

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
					if(myStream.fail()) {break; }
					input_text.push_back(remaining);
					myStream.clear();
				}
				myStream.clear();
			}
			break;
		}
	}
	// for(vector<char>::iterator anotherITR = input_text.begin(); anotherITR != input_text.end(); ++anotherITR)
 // 		cout << *anotherITR << endl;

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

void Print_random_sequence(map<string, vector<char> > sequence_Map, int model){

	//This piece of code iterates over the map and finds the most common segment to use as starting sequence (it also can print the key value pairs)
	string mostCommon;
	int length_of_character_vector = 0;
	for(map<string, vector<char> >::iterator itr = sequence_Map.begin(); itr != sequence_Map.end(); ++itr){
 		// cout << itr->first << endl;
 		if (itr->second.size() > length_of_character_vector){
 			length_of_character_vector = itr->second.size();
 			mostCommon = itr->first;
 		}
 		// for(vector<char>::iterator anotherITR = itr->second.begin(); anotherITR != itr->second.end(); ++anotherITR)
 		// 	cout << *anotherITR << endl;
 	}

 	//Count the number of characters printed and stop at 2000
 	int count = 2;
 	int position = 0;
 	char next_char;
 	cout << endl; // Start the text on a new line
 	cout << mostCommon;
 	while(count < 2000){
 		//Check that the sequence exists within my model, if not, then exit early as the program has got into a situation in which there are no characters to choose from
 		if(sequence_Map.find(mostCommon) == sequence_Map.end()){break; }
 		
 		//Picks a random position from the vector of characters that follows that particular Markov sequence
 		position = static_cast<unsigned int>(RandomChance(sequence_Map[mostCommon].size()));
 		//Prints the character corresponding to that position
 		vector<char>::iterator itr = sequence_Map[mostCommon].begin();
 		next_char = *(itr + position);
 		cout << next_char;
 		mostCommon = mostCommon.substr(1) + next_char;
 		count++;
 	}
 	cout << endl;
 	cout << endl; //Print two return line at the end for clarity

}

double RandomChance(int size)
{
 return size * (rand() / (RAND_MAX + 1.0));
}






