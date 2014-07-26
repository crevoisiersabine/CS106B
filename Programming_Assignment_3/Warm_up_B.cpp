//This program finds a subset of those numbers that sum to that target number if one exists returning true, false otherwise

#import <iostream>
#include <string>
#include <vector>
using namespace std;

bool CanMakeSum_wrapper(vector<int> nums, int targetSum, int soFar, vector<int> solution){

	// // Using Recursive backtracking
	// if(nums.size() == 0){
	// 	return (targetSum == soFar);
	// }

	// for(int i = 0; i < nums.size(); i++){
	// 	int picked = nums[i];
	// 	nums.erase(nums.begin() + i);
	// 	if (CanMakeSum_wrapper(nums, targetSum, soFar + picked) || CanMakeSum_wrapper(nums, targetSum, soFar)){
	// 		return true;
	// 	}
	// 	else{
	// 		nums.push_back(picked);
	// 	}
	// }

	// return false;

	//Without Recursive backtracking
	// Success
	if(targetSum == soFar){
		cout << endl;
		cout << "To get to " << targetSum << " you can do : " << endl;
		for(int k = 0; k < solution.size(); k++){
			cout << solution[k];
			cout << ", ";
		}
		cout << endl;
		return true;
	}

	else{
		if(nums.size() > 0){

			int chosen_number = nums.back();
			nums.pop_back();
			
			//The solutions array will keep track of the subsets chosen
			solution.push_back(chosen_number);
			//Look for subsets with chosen number
			bool one = CanMakeSum_wrapper(nums, targetSum, soFar + chosen_number, solution);

			//Look for subsets without chosen number
			solution.pop_back();
			bool two = CanMakeSum_wrapper(nums, targetSum, soFar, solution);

			return (one || two);

		}

		else{
			return false;
		}
	}
}

bool CanMakeSum(vector<int> & nums, int targetSum){
	vector<int> solution;
	return CanMakeSum_wrapper(nums, targetSum, 0, solution);
}


int main(){
	//Create vector
	vector<int> nums;
	nums.push_back(3);
	nums.push_back(7);
	nums.push_back(1);
	nums.push_back(8);
	nums.push_back(-3);

	cout << CanMakeSum(nums, 4) << endl;
	cout << CanMakeSum(nums, 7) << endl;
	cout << CanMakeSum(nums, 99) << endl;
	CanMakeSum(nums, 5);
	CanMakeSum(nums, -3);
	CanMakeSum(nums, 2);

	return 0;
}