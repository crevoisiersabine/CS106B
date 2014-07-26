//This program counts the number of election outcomes in which the block at the given index has a critical vote. 

#import <iostream>
#include <vector>
using namespace std;

void Count_Subsets(vector<int> nums, vector<int> candidate_one, vector<int> candidate_two, int element, int sum){
	
	if(nums.size() == 0){
		int cand_one = 0;
		int cand_two = 0;
		for(int i = 0; i < candidate_one.size(); i++){
			cand_one += candidate_one[i];
		}
		for(int j = 0; j < candidate_two.size(); j++){
			cand_two += candidate_two[j];
		}
		if((cand_one < sum/2.0 && element + cand_one > cand_two) || (cand_two < sum/2.0 && element + cand_two > cand_one)){
			cout << sum << endl;
			cout << cand_one << endl;
			cout << cand_two << endl;
			cout << "critical vote" << endl;
		}
	}
	
	if(nums.size() > 0){

		int chosen_number = nums.back();
		nums.pop_back();
			
		//Element chooses candidate one
		candidate_one.push_back(chosen_number);
		//Look for subsets which satisfy this condition
		Count_Subsets(nums, candidate_one, candidate_two, element, sum);
		//Element chooses candidate one
		candidate_one.pop_back();
		candidate_two.push_back(chosen_number);
		//Look for subsets which satisfy this condition
		Count_Subsets(nums, candidate_one, candidate_two, element, sum);
	}
}

int Sum_Vector(vector<int> & blocks){
	int sum = 0;
	for(int h = 0; h < blocks.size(); h++){
		sum += blocks[h];
	}
	return sum;
}

void CountCriticalVotes(vector<int> & blocks, int blockIndex){
	vector<int> candidate_one;
	vector<int> candidate_two;
	int element = blocks[blockIndex];
	int sum = Sum_Vector(blocks);
	blocks.erase(blocks.begin() + blockIndex);
	Count_Subsets(blocks, candidate_one, candidate_two, element, sum);
}


int main(){
	vector<int> blocks;
	blocks.push_back(4);
	blocks.push_back(2);
	blocks.push_back(7);
	blocks.push_back(4);
	CountCriticalVotes(blocks, 3);
	while(blocks.size() != 0){ blocks.pop_back();}
	blocks.push_back(4);
	blocks.push_back(2);
	blocks.push_back(7);
	blocks.push_back(4);
	CountCriticalVotes(blocks, 1);
	return 0;
}