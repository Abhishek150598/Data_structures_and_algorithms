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

	vector<int> shortest_path(int src)
	{
		set < pair<int, int> > dset;
		vector <int> dist(V + 1, INT_MAX);
		vector <bool> visited(V + 1, false);

		// Setting the distance of source as zero
		dist[src] = 0;

		// Inserting all the vertex-distance pairs into the set dset
		for(int i = 1; i <= V; i++)
		{
			dset.insert(make_pair(dist[i], i));
		}

		while(!dset.empty())
		{
			// Erasing the smallest distance vertex from the set, and marking it visited.
			int u = dset.begin()->second;
			dset.erase(dset.begin());
			visited[u] = true;

			// Iterating through its neighbours
			vector < pair<int, int> >::iterator it;
			for(it = adjl[u].begin(); it != adjl[u].end(); it++)
			{
				int v = it->first;
				int weight = it->second;

				// Condition for relaxation
				if(dist[v] > dist[u] + weight && !visited[v])
				{
					dset.erase(make_pair(dist[v],v));
					dist[v] = dist[u] + weight;
					dset.insert(make_pair(dist[v],v));
				}
			}
		}

		return dist;

	}
};

int main()
{
	int N, M, v;

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

	cout << "Enter the vertex from which shortest distance is required: " << endl;
	cin >> v;

	vector <int> dist = g.shortest_path(v);

	cout<< "The shortest distances are: " << endl;
	for(int i = 1; i <= N; i++)
	{
		cout << i << " " << dist[i] << endl;
	} 
}