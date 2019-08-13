// Disjoint set implementation using path compression and union by rank
#include <bits/stdc++.h>
using namespace std;

class disjoint_set
{
	int *parent;
	int *rank;
	int size;

	public:

	disjoint_set(int size)
	{ 
		this->size = size;
		parent = new int[size];
		rank = new int[size];

		for(int i = 0; i < size; i++)
		{
			parent[i] = i;
			rank[i] = 1;
		}
	}

	int find(int i)
	{
		if(parent[i] != i)
			return parent[i] = find(parent[i]); // Path compression
		return i;
	}

	bool Union(int x, int y)
	{
		int xset = find(x);
		int yset = find(y);

		if(xset == yset)
			return false; // Useful for cycle detection in a graph

		if(rank[xset] > rank[yset])
			parent[yset] = xset;
		else if(rank[xset] < rank[yset])
			parent[xset] = yset;
		else
		{
			parent[yset] = xset;
			rank[xset] += 1;
		}

		return true;
	}

};
