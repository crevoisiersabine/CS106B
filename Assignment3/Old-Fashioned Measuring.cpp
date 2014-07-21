// This program finds out whether a set of weights can measure a given quantity

#include <iostream>
#include <vector>
using namespace std;

//Recursive function
bool IsMeasurable(int target, vector<int> weights){
	if(target == 0) { return true; } //base case

	else if(weights.size() > 0) {
		int picked_weight = weights.back();
		weights.pop_back();
		if(IsMeasurable(target - picked_weight, weights)) { return true; }
		if(IsMeasurable(target + picked_weight, weights)) { return true; }
		if(IsMeasurable(target, weights)) { return true; }
	}
	
	return false;
}

// //Alternate method - from Julie Zelenski's solution
// bool IsMeasurable(int target, vector<int>& weights, int count){
// 	if(target == 0) { return true; } //Base case

// 	//I have looked through each element of the weights array (adding to each side of the weight balance and choosing to discard), no more choices left
// 	if (count >= weights.size()){
// 		return false;
// 	}

// 	int picked_weight = weights[count];
// 	return (IsMeasurable(target - picked_weight, weights, count + 1) || IsMeasurable(target + picked_weight, weights, count + 1) || IsMeasurable(target, weights, count + 1));
// }

/* Main function body */
int main() {

	vector<int> sampleWeights;
	sampleWeights.push_back(1);
	sampleWeights.push_back(3);
	sampleWeights.push_back(6);
	cout << "Is it possible to weigh 7 ? " << IsMeasurable(7, sampleWeights, 0) << endl;
	cout << "Is it possible to weigh 9 ? " << IsMeasurable(9, sampleWeights, 0) << endl;
	cout << "Is it possible to weigh 36 ? " << IsMeasurable(36, sampleWeights, 0) << endl;
	cout << "Is it possible to weigh 6 ? " << IsMeasurable(6, sampleWeights, 0) << endl;
	cout << "Is it possible to weigh 4 ? " << IsMeasurable(4, sampleWeights, 0) << endl;

	return 0;
}