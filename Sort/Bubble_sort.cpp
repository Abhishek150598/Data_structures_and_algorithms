//Program to implement bubble sort

#include<bits/stdc++.h>
using namespace std;

void swap(int* a, int i, int j)
{
	int temp;
	temp = a[i];
	a[i] = a[j];
	a[j] = temp;
}

void bubble_sort(int *a, int n)
{
	for(int i = 0;i < n - 1; i++)
	{
		for(int j = 0; j < n - i - 1; j++)
		{
			if(a[j] > a[j + 1])
				swap(a, j, j + 1);
		}
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
	bubble_sort(arr, n);
	cout << "The sorted array is: ";
	for(int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}