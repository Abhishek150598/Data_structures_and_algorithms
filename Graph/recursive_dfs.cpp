// Program to visit all nodes of a connected undirected graph using recursive DFS

#include <bits/stdc++.h>
using namespace std;

vector <int> adjl[1000001];
bool visited[1000001];

void dfs(int i)
{
	visited[i] = true;

	// Replace with relevant operation
	cout << "Vertex " << i << " is visited." << endl;

	vector <int>::iterator it = adjl[i].begin();
	while(it != adjl[i].end())
	{
		if(!visited[*it])
			dfs(*it);
		it++;
	}
}

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
	dfs(1);

}