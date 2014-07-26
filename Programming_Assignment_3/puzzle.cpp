//This function returns true if it is possible to solve the puzzle from the starting configuration and false if it is impossible.

#import <iostream>
#include <vector>
using namespace std;


bool Solvable(int start, vector<int> squares, vector<int> sequence){

	// Using Recursive backtracking
	if(start == squares.size() - 1){
		for(int g = 0; g < sequence.size(); g++){
			cout << sequence[g];
		}
		cout << endl;
		return true;
	}

	int steps = squares[start];
	//I have tried to solve from position start so I put a zero there
	squares[start] = 0;
		
	//Check that I can move to the right
	if(squares.size() > steps + start && (squares[start + steps] != 0 || (start + steps) == squares.size() - 1)) {
		//Try solving by moving to the right
		start = start + steps;
		sequence.push_back(steps);
		if (Solvable(start, squares, sequence)){
			return true;
		}
		//Undo move to the right if couldn't solve
		else{
			sequence.pop_back();
			start = start - steps;
		}
	}

	//Check that I can move to the left
	if (squares[start - steps] != 0 && (start - steps) >= 0){
		//Try solving by moving to the left
		start = start - steps;
		sequence.push_back(-steps);
		if (Solvable(start, squares, sequence)){
			return true;
		}
		//Undo move to the left if couldn't solve
		else{
			sequence.pop_back();
			start = start + steps;
		}
	}
	//I couldn't solve from position start so I undo what I did
	squares[start] = steps;
	return false;
}

int main(){
	vector<int> sequence;
	vector<int> puzzle;
	puzzle.push_back(3);
	puzzle.push_back(6);
	puzzle.push_back(4);
	puzzle.push_back(1);
	puzzle.push_back(3);
	puzzle.push_back(4);
	puzzle.push_back(2);
	puzzle.push_back(5);
	puzzle.push_back(3);
	puzzle.push_back(0);
	cout << Solvable(0, puzzle, sequence) << endl;
	vector<int> new_puzzle;
	sequence.clear();
	new_puzzle.push_back(3);
	new_puzzle.push_back(1);
	new_puzzle.push_back(2);
	new_puzzle.push_back(3);
	new_puzzle.push_back(0);
	cout << Solvable(3, new_puzzle, sequence) << endl;
	return 0;
}