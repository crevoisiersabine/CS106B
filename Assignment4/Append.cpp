// This program takes two linked lists and makes a new list by destructively changing the first linked list
#include <iostream>
#include <vector>
using namespace std;

struct Cell {
Cell *next;
int value;
};

void Build_List(Cell * & list, vector<int> numbers){
	if(numbers.size() != 0)
	{
		for(vector<int>::iterator iter = numbers.end() - 1; iter >= numbers.begin(); --iter){
			Cell *newOne = new Cell;
			newOne->value = *iter;
			newOne->next = list;
			list = newOne;	
		}
	}
}

Cell * Merge_lists(Cell * & list, Cell * list2){
	if(list == NULL){ list = list2;
		return list;}
	else{
		if(list->next == NULL){
			//BASE CASE
			list->next = list2;
			return list;
		}
		else{
			return Merge_lists(list->next, list2);
		}
	}
}

void Print_list(Cell *list){
	for(Cell *curr = list; curr!=NULL; curr = curr->next){
		cout<< (*curr).value << endl;
	}
	cout << '\n';
};

int main(){
	//Building my first list
	Cell *newOne = NULL;
	vector<int> numbers;
	numbers.push_back(1);
	numbers.push_back(4);
	numbers.push_back(6);
	Build_List(newOne, numbers);
	Print_list(newOne);

	//Building my second list
	Cell *second = NULL;
	vector<int> numbers2;
	numbers2.push_back(3);
	numbers2.push_back(19);
	numbers2.push_back(2);
	Build_List(second, numbers2);
	Print_list(second);

	Merge_lists(newOne, second);
	Print_list(newOne);

	return 0;
}