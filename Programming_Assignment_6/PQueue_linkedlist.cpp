/*
 *  File: PQueue_vector.cpp
 *  ------------------
 *
 *  Created by Sabine Crevoisier on 07/12/2014.
 *
 */

#include "PQueue_linkedlist.h"
#include <iostream>

using namespace std;


PQueue::PQueue(){
	head = NULL;
}

PQueue::~PQueue(){
	while(head != NULL) {
		cellT *temp = head->next;
		delete head;
		head = temp;
	}
}

int PQueue::size(){
	cellT *elem = head;
	int count = 0;
	while(elem != NULL) {
		elem = elem->next;
		count++;
	}
	delete elem;
	return count;
}

bool PQueue::isEmpty(){
	return (head==NULL);
}

void PQueue::enqueue(int newElem){
	cellT *newCell = new cellT;
	newCell->val = newElem;

	cellT *curpointer = head;
	cellT *prevpointer = NULL;

	// if the queue is empty or element is the biggest then enqueue to the front
	if (isEmpty() || newElem > head->val) {
		newCell->next = head;
		head = newCell;
	}
	else{
		// if the queue is not empty
		while(curpointer != NULL){
			if(curpointer->val < newElem){ // enqueue somewhere in the middle by finding the first element that is smaller as the link is sorted
				newCell->next = curpointer;
				prevpointer->next = newCell;
				curpointer = NULL;
			} else {
				if(curpointer->next == NULL) { // enqueue at the end as this element is the smallest one in the queue
					curpointer->next = newCell;
					newCell->next = NULL;
				}
				prevpointer = curpointer;
				curpointer = curpointer->next;
			}
		}
	}
	prevpointer = curpointer; //enable deletion of both pointers with line below
	delete curpointer;
}

int PQueue::dequeueMax(){
	if (isEmpty()) {
		cout << "Trying to dequeue empty queue" << endl;
		return -1;
	} else {
		int top = head->val;
		head = head->next;
		return top;
	}
}



