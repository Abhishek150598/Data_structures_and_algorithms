// Program to visit all nodes of a connected undirected graph using iterative DFS

#include <bits/stdc++.h>
using namespace std;

vector <int> adjl[1000001];
bool visited[1000001];

int main()
{
	int N, M, a, b;

	cout << "Enter the number of vertices and edges: " << endl;
	cin >> N >> M;

	cout << "Enter the edges: " << endl;
	for(int i = 1; i <= M; i++)
	{
		cin >> a >> b; 
		adjl[a].push_back(b);
		adjl[b].push_back(a);
	}

	memset(visited, false, sizeof(visited));

	stack <int> s;
	s.push(1);

	while(!s.empty())
	{
		// Popping the node from stack
		int v = s.top();
		s.pop();

		// Replace with relevant operation
		if(!visited[v])
		{
			visited[v] = true;
			cout << "Vertex " << v << " is visited." << endl;
		}
		
		// Pushing all its unvisited neighbours into stack
		vector <int>::iterator it;
		for(it = adjl[v].begin(); it != adjl[v].end(); it++)
		{
			if(!visited[*it])
			{
				s.push(*it);
			}
		}
	}
}