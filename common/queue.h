/*
 * queue.h
 *
 * Created: 27/02/2015 11.51.03
 *  Author: xmas79
 */ 

#ifndef QUEUE_H_
#define QUEUE_H_

template <typename T, uint8_t MAXLENGTH>
class Queue
{
protected:
	uint8_t Count;
	uint8_t FirstItemIndex;

public:
	T items[MAXLENGTH];
	
	Queue<T, MAXLENGTH>()
	{
		Count = 0;
		FirstItemIndex = 0;
	};
	
	__attribute__((always_inline)) uint8_t GetCount() { return Count; };
	__attribute__((always_inline)) bool HasItems() { return Count > 0; };
	__attribute__((always_inline)) bool IsFull() { return Count == MAXLENGTH; };
	__attribute__((always_inline)) bool IsAlmostFull() { return Count == (MAXLENGTH - 1); };
	
	//bool InsertAhead(const T& item)
	//{
		//if (Count == MAXLENGTH)
			//return false;
		//
		//if (FirstItemIndex == 0)
			//FirstItemIndex = MAXLENGTH - 1;
		//else
			//FirstItemIndex--;
		//
		//items[FirstItemIndex] = item;
		//
		//Count++;
		//
		//return true;
	//}
	
	bool Enqueue(const T& item)
	{
		if (Count == MAXLENGTH)
			return false;
		
		uint8_t idx = (Count + FirstItemIndex);
		if (idx >= MAXLENGTH)
			idx -= MAXLENGTH;
		
		items[idx] = item;
		
		Count++;
		
		return true;
	};
	
	T Dequeue()
	{
		uint8_t idx = FirstItemIndex;
		
		if (Count > 0)
			Count--;

		FirstItemIndex++;
		if (FirstItemIndex == MAXLENGTH)
			FirstItemIndex = 0;
		
		return items[idx];
	};

	__attribute__((always_inline)) T* Peek()
	{
		return &items[FirstItemIndex];
	};
};



#endif
