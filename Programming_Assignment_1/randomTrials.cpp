/* This file is written to assess whether a random error of 8% in voting machines can impact the results */

#include <iostream>
#include <string>
#include "simpio.h"
#include "random.h"
using namespace std;

// Start a random sequence
void Randomize();

/* Function prototypes */
bool estimateError(int numberVoters, double spread, double votingError);

/* Main function body */

int main() {

   // Then convert to integer by casting
   int numberVoters;
   double spread;
   double votingError;

   // Reading in using standard library as stanford simpio library returns errors whenever using getInteger and getReal
   cout << "Please enter the number of voters: " <<endl;
   cin >> numberVoters;

   while (true) {
   	 cout << "Enter percentage spread between candidates: " <<endl;
     cin >> spread;
     if (0.0 < spread < 1.0){
     	break;
     }
   }

   while (true) {
   	 cout << "Enter voting error percentage: " <<endl;
     cin >> votingError;
     if (0.0 < votingError < 1.0){
     	break;
     }
   }

   int errorCount = 0;
   for (int j = 0; j < 500; j++){
   	  if (estimateError(numberVoters, spread, votingError)){
   	  	errorCount++;
   	  }
    }
   cout << "Chance of an invalid election result after 500 trials = " << errorCount/5.0 << endl;

   return 0;
}

/* Function definition */
bool estimateError(int numberVoters, double spread, double votingError){

	int votersA = (0.5 + spread) * numberVoters;
	int votersB = (0.5 - spread) * numberVoters;
	int registeredA = 0;
	int registeredB = 0;
	// int AvotersArray[votersA];
	// int BvotersArray[votersB];

	// Create an array of actual registered votes for those who wanted to vote A based on the votingError
	for (int i = 0; i < votersA; i++) {
		if (randomChance(votingError)) {
			registeredB++;
			// AvotersArray[i] = -1;
		}
		else {
			registeredA++;
			// AvotersArray[i] = 1;
		}
	}
	// Same for voters B
	for (int i = 0; i < votersB; i++) {
		if (randomChance(votingError)) {
			registeredA++;
			// BvotersArray[i] = 1;
		}
		else {
			registeredB++;
			// BvotersArray[i] = -1;
		}
	}

	// This piece below was using arrays defined above
	// // Registered A votes correspond to 1 and registered B votes correspond to -1
	// int countA = 0;
	// int countB = 0;

	// for (int i = 0; i < votersA; i++) {
	// 	if (AvotersArray[i] == 1){
	// 		countA++;
	// 	}
	// 	else {
	// 		countB++;
	// 	}
	// }
	// for (int i = 0; i < votersB; i++) {
	// 	if (BvotersArray[i] == 1){
	// 		countA++;
	// 	}
	// 	else {
	// 		countB++;
	// 	}
	// }
	// cout << "Recorded A, B " << endl << registeredA << ", " << registeredB << "" <<endl;
	// cout << "Actual A, B " << endl << votersA << ", " << votersB << "" <<endl;

	/* This checks whether we predicted the outcome correctly or wrongly, output is error false if correct outcome
	is predicted and error true if an error has been made */
	if (registeredA > registeredB) {
		return false;
	}
	else {
		return true;
	}
}