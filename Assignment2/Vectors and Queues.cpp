#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <string>
using namespace std;

struct eMailMsg {
 string to; // i.e. "professor@stanford.edu"
 string from; // i.e. "student@stanford.edu"
 string message; // body of message
 string subject; // i.e. "CS106 Rocks!"
 int date; // date email was sent
 int time; // time email was sent
};

typedef vector<eMailMsg> Messages;

void RemoveSpam(Messages emails){
	for(int i = 0; i < emails.size(); i++){
		if (emails[i].subject == "SPAM"){
			emails.erase(emails.begin() + i);
		}
	}
}

void ReverseQueue(queue<int> &q){
	stack<int> intermediate;
	//Take elements from queue, one by one, and put them in a stack
	int number_of_loops = q.size();
	for(int i = 0; i < number_of_loops; i++){
		intermediate.push(q.front());
		q.pop();
	}
	//Take elements from stack, one by one, and put them in the new queue (they will be reversed)
	for(int j = 0; j < number_of_loops; j++){
		q.push(intermediate.top());
		intermediate.pop();
	}
}

int main() {

	//Initialise my queue for testing and add 5 integers to be reversed
	queue<int> q;
	q.push(1);
	q.push(2);
	q.push(3);
	q.push(4);
	q.push(5);

	ReverseQueue(q);

	int number_of_loops = q.size();
	for(int k = 0; k < number_of_loops; k++){
		cout << q.front() << endl;
		q.pop();
	}

	return 0;
}

