//Program to implement quick sort, last element is taken as pivot

#include<bits/stdc++.h>
using namespace std;

void swap(int* a, int i, int j)
{
	int temp;
	temp = a[i];
	a[i] = a[j];
	a[j] = temp;
}

int get_pivot(int* a, int left, int right)
{
	int pivot = a[right];
	int i = left; // i is the expected position of the pivot element
	for(int j = left; j < right; j++)
	{
		if(a[j] <= pivot)
		{
			swap(a, i, j);
			i++;
		}
	}
	swap(a, i, right);
	return i;
}

void quick_sort(int* a, int left, int right)
{
	if(left < right)
	{
		int pivot = get_pivot(a, left, right);
		quick_sort(a, left, pivot - 1);
		quick_sort(a, pivot + 1, right);
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
	bubble_sort(arr, 0, n - 1);
	cout << "The sorted array is: ";
	for(int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}