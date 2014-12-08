/*
 *  File: PQueue.h
 *  ----------------
 *
 *  Created by Sabine Crevoisier on 07/12/2014.
 *
 */

#ifndef _PQueue_h
#define _PQueue_h

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
		struct cellT {
			int val;
			cellT *next;
		};
	
		cellT * head;
};

#endif