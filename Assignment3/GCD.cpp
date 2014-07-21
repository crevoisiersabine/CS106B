// This program returns the greatest common divisor (g.c.d.) of two nonnegative integers

#include <iostream>
using namespace std;

//Recursive
int GCD(int x, int y){
	if(x%y == 0){
		return y;
	}
	else{
		return GCD(y, x%y);
	}
}

/* Main function body */
int main() {

	cout << "The GCD of 1 and 2 is: " << GCD(1, 2) << endl;
	cout << "The GCD of 9 and 3 is: " << GCD(9, 3) << endl;
	cout << "The GCD of 10 and 2 is: " << GCD(10, 2) << endl;
	cout << "The GCD of 14 and 2 is: " << GCD(14, 2) << endl;
	cout << "The GCD of 12 and 25 is: " << GCD(12, 25) << endl;
	cout << "The GCD of 122 and 243 is: " << GCD(122, 243) << endl;
	cout << "The GCD of 7 and 49 is: " << GCD(7, 49) << endl;
	cout << "The GCD of 36 and 42 is: " << GCD(36, 42) << endl;

	return 0;
}