//This program returns the number of different ways to climb a staircase of a given height taking strides of one or two stairs at a time

#import <iostream>
#include <vector>
using namespace std;

void CountWays(int numStairs, vector<string> strides) {
	if (numStairs == 0){
		cout << "A possible solution to the problem is: " << endl;
		for(int i = 0; i < strides.size(); i ++){
			cout << strides[i] << endl;
		}
	}
	if (numStairs > 0){
		//Take a big stride
		strides.push_back("big");
		CountWays(numStairs - 2, strides);
		//Take a small stride
		strides.pop_back();
		strides.push_back("small");
		CountWays(numStairs - 1, strides);
	}
}

void CountWays(int numStairs){
	vector<string> strides;
	CountWays(numStairs, strides);
}

int main(){
	CountWays(3);
	return 0;
}