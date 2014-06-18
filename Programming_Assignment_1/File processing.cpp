//This program produces a histogram from a file of exam scores

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;

//Initialise scores vector and visual vector definitions
typedef vector<int> Hist_vector;
typedef vector<string> Visual_vector;

//Function prototypes
Visual_vector make_Histogram(Hist_vector histogram_scores);
void print_Histogram(Visual_vector histogram_visual);

int main(){

	//Initialise scores vector and visual vector
	Hist_vector histogram_scores;

	//Ask user for file name until a correct one is given and open it, read it and put scores into a vector
	while(true){
		string input;
		stringstream myStream;
		int score;
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
			if (file_read.is_open()){
				while(getline(file_read, line)){
					//Push line into the stream as a string
					myStream << line;
					//Extract an integer from the stream
					myStream >> score;
					histogram_scores.push_back(score);
					myStream.clear();
				}
			}
			break;
		}
	}

	print_Histogram(make_Histogram(histogram_scores));

	return 0;
}

Visual_vector make_Histogram(Hist_vector histogram_scores){

	//Initialise the histogram visual to have size 10 have initial count zero
	Visual_vector histogram_visual;
	for(int j = 0; j < 10; j++){
		histogram_visual.push_back("");
	}

	//Update the histogram visual vector according to the scores
	for(int i = 0; i < histogram_scores.size(); i++){
		for(int j = 0; j < 10; j++){
			if (histogram_scores[i] / 10 == j){
				histogram_visual[j] += "X";
			}
		}
	}
	return histogram_visual;
}

void print_Histogram(Visual_vector histogram_visual){

	//Print the histogram visual to the console
	cout << "0-9: " << histogram_visual[0] << endl; // This is to avoid the first line to print 00-09
	for(int j = 1; j < 10; j++){
		cout << j << "0" << "-" << j << 9 << ": " << histogram_visual[j] << endl;
	}

}