//Program to implement selection sort

#include<bits/stdc++.h>
using namespace std;

void swap(int* a, int i, int j)
{
	int temp;
	temp = a[i];
	a[i] = a[j];
	a[j] = temp;
}

void selection_sort(int* a, int n)
{
	for(int i = 0; i < n; i++)
	{
		int min	= a[i];
		int pos = i;
		for(int j = i + 1; j < n; j++)
		{
			if(a[j] < min)
			{
				pos = j;
				min = a[j];
			}
		}
		swap(a, i, pos);
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
	selection_sort(arr, n);
	cout << "The sorted array is: ";
	for(int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}