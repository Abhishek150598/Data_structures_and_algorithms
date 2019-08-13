//IMPLEMENTATION OF MIN HEAP, ONE- BASED INDEXING HAS BEEN USED

#include <bits/stdc++.h>
using namespace std;

class heap
{
	int* arr;
	int size;
	int capacity;

	public:

		heap(int capacity = 1000)
		{
			this->capacity = capacity;
			size = 0;
			arr = new int[capacity];
		}

		int parent(int index)
		{
			return index/2;
		}

		int left(int index)
		{
			return 2 * index;
		}

		int right(int index)
		{
			return 2 * index + 1;
		}

		void swap(int i, int j)
		{
			int temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
		}

		void heapify(int i)
		{
			int smallest = i;
			int l = left(i);
			int r = right(i);
			if(l < size && arr[l] < arr[i])
				smallest = l;
			if(r < size && arr[r] < arr[smallest])
				smallest = r;

			if(smallest != i)
			{
				swap(smallest, i);
				heapify(smallest);
			}	
		}

		int extract_min()
		{
			if(size <= 0)
				return INT_MAX;

			if(size == 1)
			{
				size--;
				return arr[1];
			}

			int root = arr[1];
			arr[1] = arr[size];
			size--;
			heapify(1);

			return root;
		}

		void insert_key(int ele)
		{
			if(size == capacity)
			{
				cout << "Heap overflow";
				return;
			}

			size++;
			arr[size] = ele;
			int i = size;
			while(i != 1 && arr[parent(i)] > arr[i])
			{
				swap(i, parent(i));
				i = parent(i);
			}
		}

		void display()
		{
			for(int i = 1; i <= size; i++)
			{
				cout << arr[i] << " ";
			}
			cout << endl;
		}

};