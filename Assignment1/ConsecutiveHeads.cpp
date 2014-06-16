/*
 * File: ConsecutiveHeads.cpp
 * --------------------------
 * Name: [TODO: enter name here]
 * Section: [TODO: enter section leader here]
 * This file is the starter project for the coin-flipping problem.
 * [TODO: rewrite the documentation]
 */

#include <iostream>
#include <string>
// #include "console.h"
#include "random.h"
using namespace std;

// Start a random sequence
void Randomize();

int main() {
	string choice = "";
  int numberOfHeads = 0;
  int totalFlips = 0;
  while(true){
    int randomHit = randomInteger(1, 2);
    totalFlips++;
    if (randomHit == 1){
      choice = "Heads";
      cout << "Heads" << endl;
      numberOfHeads++;
    }
    else{
   	  choice = "Tails";
      cout << "Tails" << endl;
      numberOfHeads = 0;
    }
    if (numberOfHeads == 3){
      break;
    }
  }
  cout << "It took " << totalFlips << " to get three consecutive heads." << endl;
  return 0;
}
