// PROBLEM LINK: https://practice.geeksforgeeks.org/problems/n-meetings-in-one-room/0/?track=sp-greedy&batchId=152

#include <bits/stdc++.h>
using namespace std;

struct activity
{
	int start;
	int end;
	int index;

	bool operator < (activity a)
	{
		return end < a.end;
	}
};

int main()
{
	int T;
	cin >> T;
	while(T--)
	{
		int N;
		activity a[1000];
		cin >> N;

		for(int i = 0; i < N; i++)
		{
			cin >> a[i].start;
			a[i].index = i + 1;
 		}

 		for(int i = 0; i < N; i++)
		{
			cin >> a[i].end;
 		}

 		sort(a, a+N);

 		int i = 0;
	    cout << a[i].index << " ";
	    for(int j = 1; j < N; j++)
	    {
	        if(a[j].start > a[i].end)
	        {
	            cout << a[j].index << " ";
	            i = j;
	        }
	    }
	    cout << endl;
	}
}