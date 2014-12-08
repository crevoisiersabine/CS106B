/*
 *  File: PQueue_vector.cpp
 *  ------------------
 *
 *  Created by Sabine Crevoisier on 07/12/2014.
 *
 */

#include "Chunked_list.h"
#include <iostream>
#include <math.h>

using namespace std;

PQueue::PQueue(){
	start = new cellT;
	start->numUsed = 0;
	start->next = NULL;
}

PQueue::~PQueue(){
	while(start != NULL) {
		cellT *temp = start->next;
		// delete start;
		start = temp;
	}
}

int PQueue::size(){
	cellT *elem = start;
	int count = 0;
	while(elem != NULL) {
		count += elem->numUsed;
		elem = elem->next;
	}
	// delete elem;
	return count;
}

bool PQueue::isEmpty(){
	return (start->numUsed == 0);
}

void PQueue::enqueue(int newElem){
	cellT *elem = start;
	int positioned = 0;
	while(elem != NULL && positioned ==0) {
		if (elem->next != NULL && elem->next->arr[0] > newElem) {
			elem = elem->next;
		} else {
			if(elem->numUsed == MaxElemsPerBlock){
				Split(elem);
			} else {
				int index = FindIndex(elem, newElem);
				if(index == -1) {
					elem->arr[elem->numUsed++] = newElem;
					positioned = 1;
				}
				else {
					for(int i = elem->numUsed; i > index; i--){
						elem->arr[i] = elem->arr[i - 1];
					}
					elem->arr[index] = newElem;
					elem->numUsed++;
					positioned = 1;
				}
			}
		}
	}
	// cout << elem->arr[0] << endl;
	// cout << elem->arr[1] << endl;
	// cout << elem->arr[2] << endl;
	// cout << elem->arr[3] << endl;
	// cout << elem->numUsed << endl;
	// delete elem;
}

void PQueue::Split(cellT * structure){
	cellT *newCell = new cellT;
	for(int i=0; i < ceil(MaxElemsPerBlock / 2.0); i++){ //round up if MaxElemsPerBlock is odd
		newCell->arr[i] = structure->arr[MaxElemsPerBlock / 2 + i];
		newCell->numUsed++;
		structure->arr[MaxElemsPerBlock / 2 + i] = 0; //reset to zero
		structure->numUsed--;
	}
	//re-wire the pointers
	newCell->next = structure->next;
	structure->next = newCell;
}

int PQueue::FindIndex(cellT * structure, int elem){
	for(int i = 0; i < structure->numUsed; i++){
		if(structure->arr[i] < elem){
			return i;
		}
	}
	return -1;
}

int PQueue::dequeueMax(){
	if (isEmpty()) {
		cout << "Trying to dequeue empty queue" << endl;
		return -1;
	} else {
		int top = start->arr[0];
		for(int i = 0; i < (start->numUsed - 1); i++){
			start->arr[i] = start->arr[i + 1]; 
		}
		//moving one back will enable over-writing the last value that was there, as no method to delete from array (only from vector)
		start->arr[--start->numUsed] = 0; //set the value of the last element to zero as initalised
		if(start->numUsed == 0 && start->next != NULL){
			start = start->next;
		}
		return top;
	}
}



