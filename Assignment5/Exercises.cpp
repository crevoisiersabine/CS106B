// Problem 5
#import <vector>
#import <iostream>
#include <ctime>
using namespace std;

void O_N3_algorithm(){
	vector<int> testing;
	testing.push_back(2);
	testing.push_back(-5);
	testing.push_back(1);
	testing.push_back(3);
	testing.push_back(-4);
	testing.push_back(-15);
	testing.push_back(26);
	testing.push_back(9);
	testing.push_back(12);
	testing.push_back(9);
	testing.push_back(-100);
	testing.push_back(200);
	testing.push_back(-3);
	testing.push_back(10);

	vector<int> sums;
	for(int i = 0; i < testing.size(); i++){
		for(int k = 0; k < testing.size(); k++){
			int sum = 0;
			for(int j = k; j <= i; j++){
				sum += testing.at(j);
			}
			sums.push_back(sum);
		}
	}
	int sum_max = 0;
	for(int g = 0; g < sums.size(); g++){
		if (sums.at(g) > sum_max){
			sum_max = sums.at(g);
		}
	}
	cout << "The maximum sum is: " << sum_max << endl;
}

void O_N2_algorithm(){
	vector<int> testing;
	testing.push_back(2);
	testing.push_back(-5);
	testing.push_back(1);
	testing.push_back(3);
	testing.push_back(-4);
	testing.push_back(-15);
	testing.push_back(26);
	testing.push_back(9);
	testing.push_back(12);
	testing.push_back(9);
	testing.push_back(-100);
	testing.push_back(200);
	testing.push_back(-3);
	testing.push_back(10);

	vector<int> sums;
	int sum = 0;

	for(int i = 0; i < testing.size(); i++){
		sum += testing.at(i);
		sums.push_back(sum);
		int temp = sum;
		for(int j = 0; j < i; j++){
			temp -= testing.at(j);
			sums.push_back(temp);
		}
	}
	int sum_max = 0;
	for(int g = 0; g < sums.size(); g++){
		if (sums.at(g) > sum_max){
			sum_max = sums.at(g);
		}
	}
	cout << "The maximum sum is: " << sum_max << endl;
}

int cleverAlgo(vector<int> my_vector){
	int max = my_vector.at(0);
	int middle = 0;
	// int pos = 0;
	for(int i = 1; i < my_vector.size(); i++){

		if(my_vector.at(i) > 0){
			if(max + middle + my_vector.at(i) > max && max + middle + my_vector.at(i) > my_vector.at(i)){
				max = max + my_vector.at(i) + middle;
				middle = 0;
			}
			else { //if((middle + max) < 0)
				max = my_vector.at(i);
				middle = 0;
			}
		}
		else{
			middle += my_vector.at(i);
		}

		// Longer implementation
		// if(my_vector.at(i) > 0 && (i - pos) == 1){
		// 	max = max + my_vector.at(i);
		// 	pos = i;
		// }
		// else if(my_vector.at(i) > 0 && (i - pos) != 1){
		// 	if(max + middle + my_vector.at(i) > max && max + middle + my_vector.at(i) > my_vector.at(i)){
		// 		max = max + my_vector.at(i) + middle;
		//		middle = 0;
		// 		pos = i;
		// 	}
		// 	else if((middle + max) < 0){
		// 		max = my_vector.at(i);
		// 		pos = i;
		// 		middle = 0;
		// 	}
		// }
		// else if(my_vector.at(i) < 0){
		// 	middle = middle + my_vector.at(i);
		// }
	}
	return max;
}

int main(){

	//TESTING FOR RUNNING TIMES

	cout << endl;

	cout << "O3 algorithm: ";
	double start = double(clock()) / CLOCKS_PER_SEC;
	O_N3_algorithm();
	O_N3_algorithm();
	O_N3_algorithm();
	double finish = double(clock()) / CLOCKS_PER_SEC;
	double elapsed = finish - start;
	cout << "Elapsed time:" << elapsed << endl << endl;
	
	cout << "O2 algorithm: ";
	start = double(clock()) / CLOCKS_PER_SEC;
	O_N2_algorithm();
	O_N2_algorithm();
	O_N2_algorithm();
	finish = double(clock()) / CLOCKS_PER_SEC;
	elapsed = finish - start;
	cout << "Elapsed time:" << elapsed << endl << endl;

	vector<int> testing;
	testing.push_back(2);
	testing.push_back(-5);
	testing.push_back(1);
	testing.push_back(3);
	testing.push_back(-4);
	testing.push_back(-15);
	testing.push_back(26);
	testing.push_back(9);
	testing.push_back(12);
	testing.push_back(9);
	testing.push_back(-100);
	testing.push_back(200);
	testing.push_back(-3);
	testing.push_back(10);
	cout << "Clever algorithm: ";
	start = double(clock()) / CLOCKS_PER_SEC;
	cout << cleverAlgo(testing) << endl;
	cout << cleverAlgo(testing) << endl;
	cout << cleverAlgo(testing) << endl;
	finish = double(clock()) / CLOCKS_PER_SEC;
	elapsed = finish - start;
	cout << "Elapsed time:" << elapsed << endl;

	return 0;
}