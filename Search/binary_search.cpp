#include <bits/stdc++.h>
using namespace std;

int binary_search(int* a, int left, int right, int ele)
{
	
	if(left <= right)
	{
		int mid = (left + right) / 2;

		if(a[mid] == ele)
			return mid;
		if(a[mid] > ele)
			return binary_search(a, left, mid - 1, ele);
		return binary_search(a, mid + 1, right, ele);
	}
	return -1;
	
}
int main()
{
	int arr[1000], n, ele;
	cout << "Enter array size: ";
	cin >> n;
	cout << "Enter the elements in sorted order: ";
	for(int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	cout << "Enter the search element: ";
	cin >> ele;
	int pos = binary_search(arr, 0, n - 1, ele);
	if(pos == -1)
		cout << "Element not found!" << endl;
	else
		cout << "Element found at position " << pos << endl;

}