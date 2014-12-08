/*
 *  File: PQueue.h
 *  ----------------
 *
 *  Created by Sabine Crevoisier on 08/12/2014.
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
		static const int MaxElemsPerBlock = 5;

		struct cellT {
			int arr[MaxElemsPerBlock];
			int numUsed;
			cellT *next;
		};
		
		cellT * start;
		void Split(cellT * structure);
		int FindIndex(cellT * structure, int elem);
};

#endif