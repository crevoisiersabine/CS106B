// This program constructs a linked list
#include <vector>
#include <iostream>
#include <string>
using namespace std;

struct Cell {
Cell *next;
int value;
};


int Sum_recursive(Cell *list, int sum_int);

void Print_list(Cell *list){
	for(Cell *curr = list; curr!=NULL; curr = curr->next){
		cout<< (*curr).value << endl;
	}
};

// Cell * ConvertToList(vector<int> integers){

// 	Cell *listHead = NULL;

// 	for(vector<int>::iterator iter = integers.begin(); iter!=integers.end(); ++iter){
// 		Cell *newOne = new Cell;
// 		newOne->value = *iter;
// 		newOne->next = listHead;
// 		listHead = newOne;	
// 	}

// 	return listHead;
// };

//RECURSIVE
void ConvertToList(Cell * & listHead, vector<int> integers){

	if (integers.size() != 0){
		//This is to print in the same direction as entry
		Cell *newOne = new Cell;
		newOne->value = integers[integers.size() - 1];
		newOne->next = listHead;
		listHead = newOne;
		integers.pop_back();
		ConvertToList(listHead, integers);

		// // This is to print the list backwards from entry
		// int I_need_this = integers[integers.size() - 1];
		// integers.pop_back();
		// ConvertToList(listHead, integers);
		// Cell *newOne = new Cell;
		// newOne->value = I_need_this;
		// newOne->next = listHead;
		// listHead = newOne;
	}
};

//Recursive SUM------------------------------------------------------------
int SumList(Cell *list){
	int sum_int = 0;
	return Sum_recursive(list, sum_int);
};

int Sum_recursive(Cell *list, int sum_int){
	if(list->next == NULL) {return (sum_int += list->value); }
	else{
		sum_int += list->value;
		return Sum_recursive(list->next, sum_int);
	}
};

//Iterative SUM------------------------------------------------------------
int SumList_iter(Cell *list){
	int sum_int = 0;
	for(Cell *curr = list; curr!=NULL; curr = curr->next){
		sum_int += (*curr).value;
	}
	return sum_int;
};



int main(){

	vector<int> input;
	input.push_back(1);
	input.push_back(2);
	input.push_back(3);
	input.push_back(4);
	input.push_back(5);	

	Cell *listHead = NULL;
	ConvertToList(listHead, input);
	Print_list(listHead);
	cout << " " << endl;
	cout << SumList(listHead) << endl;
	
	cout << " " << endl;
	cout << SumList_iter(listHead) << endl;

return 0;
}