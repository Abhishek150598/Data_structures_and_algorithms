// Dijkstra's shortest path algorithm using set STL, 1 based indexing used for vertices

#include <bits/stdc++.h>
using namespace std;

class Graph
{
	int V;
	vector < pair<int, int> > *adjl;

	public:

	Graph(int V)
	{
		this->V = V;
		adjl = new vector < pair<int, int> >[V + 1];
	}

	void add_edge(int u, int v, int w)
	{
		adjl[u].push_back(make_pair(v,w));
		adjl[v].push_back(make_pair(u,w));
	}

	void prim()
	{
		// Declaring the data structures
		set < pair<int, int>> keyset;
		vector <int> key(V + 1, INT_MAX);
		vector <int> parent(V + 1, -1);
		vector <bool> visited(V + 1, false);

		//Setting the key of first vertex as zero
		key[1] = 0;

		//Inserting the key-vertex pairs in the set
		for(int i = 1; i <= V; i++)
		{
			keyset.insert(make_pair(key[i], i));
		}

		while(!keyset.empty())
		{
			// Erasing the smallest key vertex from the set, and marking it visited
			int u = keyset.begin()->second;
			keyset.erase(keyset.begin());
			visited[u] = true;

			// Iterating through its neighbours
			vector < pair<int, int> >::iterator it;
			for(it = adjl[u].begin(); it != adjl[u].end(); it++)
			{
				int v = it->first;
				int weight = it->second;

				// Condition for updating the key
				if(weight < key[v] && !visited[v])
				{
					keyset.erase(make_pair(key[v],v));
					key[v] = weight;
					keyset.insert(make_pair(key[v],v));
					parent[v] = u;
				}
			}

		}


		// Displaying the edges of the minimum spanning tree
		cout << "The edges of the minimum spanning tree are: ";
		for(int i = 2; i <= V; i++)
		{
			cout << parent[i] << " " << i << endl;
		}

	}
};

int main()
{
	int N, M;

	cout << "Enter the number of vertices and edges: " << endl;
	cin >> N >> M;

	Graph g(N);

	cout << "Enter the edges and their weights: " << endl;
	for(int i = 1; i <= M; i++)
	{
		int v1, v2, weight;
		cin >> v1 >> v2 >> weight; 
		g.add_edge(v1, v2, weight);
		
	}

	g.prim();

}