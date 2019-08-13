#include <bits/stdc++.h>
#include "BST.cpp"
using namespace std;

int main()
{
	BST b;
	b.insert(5);
	b.insert(7);
	b.insert(9);
	b.insert(13);
	b.insert(2);
	b.insert(4);
	b.insert(5);
	cout << b.search(3) << endl;
	cout << b.search(13) << endl;
	b.inorder();

}
