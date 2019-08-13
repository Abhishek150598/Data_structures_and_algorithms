#include <bits/stdc++.h>
using namespace std;

class Stack
{
	int top;
	int *arr;
	int capacity;

	public:

	Stack(int capacity)
	{
		this->capacity = capacity;
		arr = new int[capacity];
		top = -1;
	}

	bool empty()
	{
		return top == -1;
	}

	bool full()
	{
		return top == capacity - 1;
	}

	void push(int e)
	{
		if(full())
		{
			cout << "Stack Overflow" << endl;
			return;
		}
		top++;
		arr[top] = e;
	}

	int pop()
	{
		if(empty())
		{
			cout << "Stack is empty" << endl;
			return INT_MIN;
		}
		return arr[top--];
	}
};