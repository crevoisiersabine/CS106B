//This program will read a file of data and keep track of some statistics like the min, max and average scores

#include <iostream>
#include <string>
#include <fstream>
#include "simpio.h"
#include <stdlib.h> // For converting strings to double
using namespace std;

//Defined struct
struct statistics {
  double min;
  double max;
  double average;
};

//Initialise a variable of the type statistics (as per the struct defined above) called results
statistics results;

statistics readFileStats(ifstream &in)
{
	int count = 0; //Initialise the count and the sum
	double sum = 0.0;
	results.max = 0.0; /*The max will be above minimum value of zero*/
	results.min = 100.0; /*Start at 100.0 as the minimum to compare against as it is the max possible value so everyone should 
	score below and hence the min will be below*/
	string line;
	if (in.is_open()){
		while(getline(in, line)){
			//Check if stream fails, if so break out of the loop
			if (in.fail()){
			cout << "I broke :( " << endl;
			break;
			}
			//This counter counts the number of lines in the file
			count++;
			
			//This evaluates the sum of all the numbers in the file
			sum+=atof(line.c_str());

			//The following lines of code test for max and min values in the file
			if (atof(line.c_str()) > results.max){
				results.max = atof(line.c_str());
			}
			else if (atof(line.c_str()) < results.min){
				results.min = atof(line.c_str());
			}
		}
	}
	results.average = sum/count;
	return results;
}

int main() {
	ifstream in;
	while(true){
		cout << "Enter file name: ";
		string s = getLine(); //to read string input from user using simpio.h library
		in.open(s.c_str());
		//Check if stream fails, if so, let the user know, and clear the stream so we can try again
		if (!in.fail()){ break; }
		cout << "File didn't open!" << endl;
		in.clear();
	}
	results = readFileStats(in);
	cout << "The min is " << results.min << endl;
	cout << "The max is " << results.max << endl;
	cout << "The average is " << results.average << endl;
	return 0;
}


