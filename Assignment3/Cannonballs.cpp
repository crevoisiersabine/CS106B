// This program returns the number of cannonballs in a cannonball pyramid, recursively

#import <iostream>
using namespace std;

//Function prototype
int Cannonball(int height);

int main(){

	cout << "Input the height of the pyramid: " << endl;
	int height;
	cin >> height; //This part does not check that the user inputs a correct integer; if they do not, the program will fail
	cout << "The number of cannonballs in this pyramid is: " << Cannonball(height) << endl;

	return 0;
}

int Cannonball(int height){

	if (height == 1){
		return 1;
	}
	else{
		return (height*height + Cannonball(height - 1));
	}
}