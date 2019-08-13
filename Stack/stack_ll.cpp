#include <bits/stdc++.h>
#include "../Linked_list/linked_list.cpp"
using namespace std;

class Stack
{
	linked_list ll;
	int capacity;

	public:

	Stack(int capacity)
	{
		this->capacity = capacity;
	}

	bool empty()
	{
		return ll.empty_l();
	}

	bool full()
	{
		return ll.get_size() == capacity;
	}

	void push(int e)
	{
		if(full())
		{
			cout << "Stack Overflow" << endl;
			return;
		}
		
		ll.insert_front(e);
	}

	int pop()
	{
		if(empty())
		{
			cout << "Stack is empty" << endl;
			return INT_MIN;
		}

		int e = ll.get_front();
		ll.delete_front();
		return e;
	}
};

