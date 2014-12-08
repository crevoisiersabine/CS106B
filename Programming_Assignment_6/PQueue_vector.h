/*
 *  File: PQueue.h
 *  ----------------
 *
 *  Created by Sabine Crevoisier on 06/12/2014.
 *
 */

#ifndef _PQueue_h
#define _PQueue_h

#include <vector>
using namespace std;

class PQueue
{
	public:
		PQueue();
		~PQueue();
		int size();
		bool isEmpty();
		void enqueue(int newElem);
		int dequeueMax();

	private:
		vector<int> q;
};

#endif