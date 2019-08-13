#include <bits/stdc++.h>
#include "queue_array.cpp"
using namespace std;

int main()
{
	Queue q(30);
	q.enqueue(29);
	q.enqueue(32);
	q.enqueue(55);
	cout << q.dequeue() << endl;
	cout << q.dequeue() << endl;
	cout << q.dequeue() << endl;
	cout << q.dequeue() << endl;
	

}