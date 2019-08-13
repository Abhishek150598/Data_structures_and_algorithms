#include <bits/stdc++.h>
using namespace std;

void linear_search(int* a, int n, int ele)
{
	for(int i = 0; i < n; i++)
	{
		if(a[i] == ele)
		{
			cout << "Element found at position " << i << endl;
			return;
		}
	}
	cout << "Element not found" << endl;
	return;
}

int main()
{
	int arr[1000], n, ele;
	cout << "Enter array size: ";
	cin >> n;
	cout << "Enter the elements: ";
	for(int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	cout << "Enter the search element: ";
	cin >> ele;
	linear_search(arr, n, ele);
}