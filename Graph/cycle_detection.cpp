// Find whether a given graph contains a cycle using disjoint set

#include <bits/stdc++.h>
#include "../Advanced_algos/disjoint_set.cpp"
using namespace std;

class Graph
{
	int V;
	vector < pair<int, int> > edge;

	public:

	Graph(int V)
	{
		this->V = V;
	}

	void add_edge(int u, int v)
	{
		edge.push_back(make_pair(u, v));
	}

	bool has_cycle()
	{
		disjoint_set ds(V);
		for(int i = 0; i < edge.size(); i++)
		{
			int u = edge[i].first;
			int v = edge[i].second;
			if(!ds.Union(u, v))
				return true;
		}
		return false;

	}
};

int main()
{
	int N, M, v;

	cout << "Enter the number of vertices and edges: " << endl;
	cin >> N >> M;

	Graph g(N);

	cout << "Enter the edges: " << endl;
	for(int i = 1; i <= M; i++)
	{
		int v1, v2;
		cin >> v1 >> v2; 
		g.add_edge(v1, v2);
		
	}

	if(g.has_cycle())
		cout << "Graph has a cycle" << endl;
	else
		cout << "Graph doesn't have a cycle" << endl; 
}