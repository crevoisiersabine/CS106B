/*This program will test for whether a number is a perfect number or not. A perfect number corresponds
to a number that equals the sum of its divisors, including one.*/

#include <iostream>
#include <string>
#include <sstream>
#include "simpio.h"
using namespace std;


/* Function prototypes */
bool isPerfect(int number);

int main() {
	// Using getLine istead of getInteger as getInteger keps returning an error whenever imteger was input
	int upTo = getInteger("Please enter an integer up to which you want to check for perfect numbers: ");
	for (int i = 2; i < (int) upTo + 1; i++){
		if (isPerfect(i))
			cout << "This is a perfect number " << i << "." << endl;
	}
	return 0;

}

/* Function isPerfect. This tests for whether the number passed as an argument is a perfect number; if it is, true
is returned, false otherwise. */

bool isPerfect(int number){
	int sumOfDivisors = 0;
	for (int j = 1; j < number; j++){
		if (number%j == 0){
			sumOfDivisors += j;
		}
	}

	if (sumOfDivisors == number){
		return true;
	}
	else {
		return false;
	}
}