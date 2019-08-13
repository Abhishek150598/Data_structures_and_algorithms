#include <bits/stdc++.h>
#include "../Tree/heap.cpp"
using namespace std;

void heap_sort(int* a, int n)
{
	heap h;
	for(int i = 0; i < n; i++)
	{
		h.insert_key(a[i]);
	}

	for(int i = 0; i < n; i++)
	{
		a[i] = h.extract_min();
	}
}

int main()
{
	int arr[1000], n;
	cout << "Enter array size: ";
	cin >> n;
	cout << "Enter the elements: ";
	for(int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	heap_sort(arr, n);
	cout << "The sorted array is: ";
	for(int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}