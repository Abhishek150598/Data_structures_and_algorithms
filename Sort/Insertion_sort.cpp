//Program to implement insertion sort

#include<bits/stdc++.h>
using namespace std;

void insertion_sort(int* a, int n)
{
	for(int i = 1; i < n; i++)
	{
		int ele = a[i];
		int j;
		for(j = i - 1; (j >= 0) && (a[j] > ele); j--)
		{
			a[j + 1] = a[j];
		}
		a[j + 1] = ele;
	
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
	insertion_sort(arr, n);
	cout << "The sorted array is: ";
	for(int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}