// Implementing a queue using a fixed size array

#include <bits/stdc++.h>
using namespace std;

class Queue
{
	int front, rear, size;
	int *arr;
	int capacity;

	public:

	Queue(int capacity)
	{
		this->capacity = capacity;
		front = 1;
		rear = 0;
		size = 0;
		arr = new int[capacity];
	}

	bool empty()
	{
		return size == 0;
	}

	bool full()
	{
		return size == capacity;
	}

	void enqueue(int e)
	{
		if(full())
		{
			cout << "Queue is full" << endl;
			return;
		}

		rear = (rear + 1) % capacity;
		arr[rear] = e;
		size++;
	}

	int dequeue()
	{
		if(empty())
		{
			cout << "Queue is empty" << endl;
			return INT_MIN;
		}

		int e = arr[front];
		front = (front + 1) % capacity;
		size--;
		return e;
	}

};