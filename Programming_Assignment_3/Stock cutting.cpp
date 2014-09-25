//This program returns the optimal number of stock pipes to buy in order to optmise cost and minimise waste

#import <iostream>
#include <vector>
using namespace std;

void Wrapper_function(vector<int> &requests, int stockLength);

void Stock_Cutting(vector<int> soFar, vector<int> rest, int stockLength, vector<int> requests, int count, vector<vector<int> > selection, vector<vector<vector<int> > > &final_selection, vector<int> &count_vector){

	if (rest.size() != 0) {
		soFar.push_back(rest.at(rest.size() - 1)); //push last element of rest into soFar
		rest.pop_back();

		//Calculate the sum of the current subset
		int sum = 0;
		for (int i=0; i<soFar.size(); i++){
			sum += soFar.at(i);
		}
		if (sum <= stockLength){
			Stock_Cutting(soFar, rest, stockLength, requests, count, selection, final_selection, count_vector); // include last element from rest vector
			soFar.pop_back();
			Stock_Cutting(soFar, rest, stockLength, requests, count, selection, final_selection, count_vector); // exclude last element from rest vector
		}
		else { //I need to do this loop to explore all possibilities of subsets
			soFar.pop_back();
			Stock_Cutting(soFar, rest, stockLength, requests, count, selection, final_selection, count_vector); // exclude last element from rest vector
		}
	}

	//THIS IS A BASE CASE - I HAVE FOUND A SUBSET--------------------------------------------------------------
	else{
		if (soFar.size() != 0){ //only print subsets with something in it; not the empty one
			count += 1;
			// vector<int> intermediate;
		    for (int i = 0; i < soFar.size(); i++){
		  		// intermediate.push_back(soFar.at(i));
		  	
		  		int pos = find(requests.begin(), requests.end(), soFar.at(i)) - requests.begin(); //Find the position of each item in subset
		  		requests.erase(requests.begin() + pos);
		  	}
		    selection.push_back(soFar); //include current subset in current selection

			if (requests.size() == 0){
				count_vector.push_back(count);
				final_selection.push_back(selection);
			}

			vector<int> soFar; //re-initalise the vector soFar to start recursion again with smaller requests vector
			Stock_Cutting(soFar, requests, stockLength, requests, count, selection, final_selection, count_vector);
		}
	}
}

int main(){

	//Create the requests vector
	vector<int> requests;
	requests.push_back(1);
	requests.push_back(1);
	requests.push_back(7);
	// requests.push_back(4);
	requests.push_back(3);
	requests.push_back(9);
	requests.push_back(9);
	Wrapper_function(requests, 10);

	return 0;
}

void Wrapper_function(vector<int> &requests, int stockLength){
	//First check whether the smaller bits add up to less than the pipe length, in which case we are done, we only need 1 piece
	int sum = 0;
	for (int i=0; i<requests.size(); i++){
		sum += requests.at(i);
	}
	if (sum <= stockLength){
		cout << "You can use just the one piece !!" << endl;
	}

	else { // In the case that we need more than one piece
		vector<int> soFar;
		vector<vector<int> > selection;
		vector<vector<vector<int> > > final_selection;
		vector<int> count_vector;

		Stock_Cutting(soFar, requests, stockLength, requests, 0, selection, final_selection, count_vector);

		//Check which returned the min count - this does not return all combinations but the first it finds with minimal number of bars
		int min_count = stockLength;
		int index = 0;
		for (int j = 0; j < count_vector.size(); j++){
			if(count_vector.at(j) < min_count){
				min_count = count_vector.at(j);
				index = j;
			}
		}
		cout << "I need " << min_count << " metal bars" << endl;
		cout << "Subset are:";
		for (int i = 0; i < final_selection.at(index).size(); i++){
		 	for (int j = 0; j < final_selection.at(index).at(i).size(); j++){
			 	cout << " ";
			  	cout << final_selection.at(index).at(i).at(j);
			}
			cout << ",";
		}
	  	cout << '\n' << endl;
	}
}