/*
 *  File: PQueue_vector.cpp
 *  ------------------
 *
 *  Created by Sabine Crevoisier on 06/12/2014.
 *
 */

#include "PQueue_vector.h"

PQueue::PQueue(){}

PQueue::~PQueue(){}

int PQueue::size(){
	return q.size();
}

bool PQueue::isEmpty(){
	return q.empty();
}

void PQueue::enqueue(int newElem){
	q.push_back(newElem);
}

int PQueue::dequeueMax(){
	int index = -1;
	int max = 0;
	for(int i=0; i < q.size(); i++){
		if (q.at(i) > max) {
			max = q.at(i);
			index = i;
		}
	}
	if(isEmpty() == 1) return -1;
	else {
		int deleted = q.at(index);
		q.erase(q.begin() + index);
		return deleted;
	}
}