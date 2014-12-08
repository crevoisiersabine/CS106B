/*
 *  File: testing.cpp
 *  ------------------
 *
 *  Created by Sabine Crevoisier on 06/12/2014.
 *
 */
#include "Chunked_list.h"
#include <iostream>

using namespace std;

 int main() {

 	PQueue priority;
 	priority.enqueue(9);
 	priority.enqueue(1);
 	priority.enqueue(8);
 	priority.enqueue(3);
 	priority.enqueue(2);
 	priority.enqueue(17);
 	priority.enqueue(17);
 	priority.enqueue(-4);
 	priority.enqueue(13);
 	priority.enqueue(-82);
 	priority.enqueue(31);
 	priority.enqueue(9);
 	priority.enqueue(7);
 	priority.enqueue(1);
 	cout << priority.dequeueMax() << endl;
 	cout << priority.dequeueMax() << endl;
 	cout << priority.dequeueMax() << endl;
 	cout << priority.dequeueMax() << endl;
 	cout << priority.dequeueMax() << endl;
 	cout << priority.dequeueMax() << endl;
 	cout << priority.dequeueMax() << endl;
 	cout << priority.dequeueMax() << endl;
 	cout << priority.dequeueMax() << endl;
 	cout << priority.dequeueMax() << endl;
 	cout << priority.dequeueMax() << endl;
 	cout << priority.dequeueMax() << endl;
	return 0;
}