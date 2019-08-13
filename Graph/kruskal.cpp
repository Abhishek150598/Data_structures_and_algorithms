// Kruskal's minimum spanning tree algorithm, zero-based indexing for vertices

#include <bits/stdc++.h>
#include "../Advanced_algos/disjoint_set.cpp"
using namespace std;

class Edge
{
	public:

	int vertex1;
	int vertex2;
	int weight;

	bool operator<(const Edge& e) const
	{
		return weight < e.weight;
	}
};

class Graph
{
	int V;
	multiset <Edge> edge;

	public:

	Graph(int V)
	{
		this->V = V;
	}

	void add_edge(int u, int v, int w)
	{
		edge.insert({u, v, w});
	}

	Graph kruskal()
	{
		Graph MST(V);
		disjoint_set ds(V);

		for(auto i = edge.begin(); i !=edge.end(); i++)
		{
			int u = i->vertex1;
			int v = i->vertex2;
			int w = i->weight;
			if(ds.Union(u, v))
				MST.add_edge(u, v, w);
		}

		return MST;
	}

	void show_edges()
	{
		for(auto i = edge.begin(); i !=edge.end(); i++)
		{
			cout << i->vertex1 << " " << i->vertex2 << endl;
		}
	}
};

int main()
{
	int N, M, v;

	cout << "Enter the number of vertices and edges: " << endl;
	cin >> N >> M;

	Graph g(N);

	cout << "Enter the edges and weights: " << endl;
	for(int i = 1; i <= M; i++)
	{
		int v1, v2, weight;
		cin >> v1 >> v2 >> weight; 
		g.add_edge(v1, v2, weight);
		
	}

	Graph MST = g.kruskal();

	cout << "The edges in the minimum spanning tree are: " << endl;
	MST.show_edges(); 
}