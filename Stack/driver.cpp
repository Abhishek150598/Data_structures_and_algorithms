#include <bits/stdc++.h>
#include "stack_ll.cpp"
using namespace std;

int main()
{
	Stack s(5);
	s.push(5);
	s.push(10);
	s.push(50);
	s.push(12);
	cout << s.pop() << endl;
	cout << s.pop() << endl;
	cout << s.pop() << endl;
	cout << s.pop() << endl;
	cout << s.pop() << endl;

}