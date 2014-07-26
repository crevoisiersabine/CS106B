//This program prints the binary representation of a non-negative integer

#import <iostream>
#include <string>
#include <math.h> //to use remainder %
using namespace std;


string PrintInBinary_wrapper(int number, string binary){
	if(number == 0){
		return "0";
	}
	if(number == 1){
		 return "1";
	}
	else{
		return binary = PrintInBinary_wrapper(number/2, binary) + PrintInBinary_wrapper(number%2, binary) + binary;
	}
}


void PrintInBinary(int number){
	cout << PrintInBinary_wrapper(number, "") << endl;
}

int main(){
	PrintInBinary(1);
	PrintInBinary(2);
	PrintInBinary(3);
	PrintInBinary(4);
	PrintInBinary(5);
	PrintInBinary(6);
	PrintInBinary(7);
	PrintInBinary(8);
	PrintInBinary(9);
	return 0;
}