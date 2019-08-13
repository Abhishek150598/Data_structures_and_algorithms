//Program to implement merge sort

#include<bits/stdc++.h>
using namespace std;

void merge(int* a, int left, int mid, int right)
{
	int size1 = mid - left + 1;
	int size2 = right - mid;
	int L[size1], R[size2];
	//Filling the left array
	for(int i = 0; i < size1; i++)
	{
		L[i] = a[left + i];
	}
	//Filling the right array
	for(int i = 0; i < size2; i++)
	{
		R[i] = a[mid + 1 + i];
	}

	int i = 0, j = 0, k = left;
	while((i < size1) && (j < size2))
	{
		if(L[i] < R[j])
		{
			a[k] = L[i];
			i++;
		}
		else
		{
			a[k] = R[j];
			j++;
		}
		k++;
	}

	while(i < size1)
	{
		a[k] = L[i];
		i++;
		k++;
	}

	while(j < size2)
	{
		a[k] = R[j];
		j++;
		k++;
	}
}

void merge_sort(int* a, int left, int right)
{
	int mid = (left + right) / 2;
	if(left < right)
	{
		merge_sort(a, left, mid);
		merge_sort(a, mid + 1, right);
		merge(a, left, mid, right);
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
	merge_sort(arr, 0, n - 1);
	cout << "The sorted array is: ";
	for(int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}
