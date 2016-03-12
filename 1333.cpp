#include <iostream>
#include <vector>

using namespace std;

void DFS_visit(int n, int u, vector <int>& color, vector<vector<int> >& matrix, bool& flag)
{
	color[u] = 1;
	for (int v = 0; v < n; ++v)
	{
		if (matrix[u][v] != 0)
		{
			if (color[v] == 1)
				flag = false;
			if (color[v] == 0)
				DFS_visit(n, v, color, matrix, flag);
		}
	}
	color[u] = 2;
}
bool DFS(int n, vector <int>& color, vector<vector<int> >& matrix)
{
	bool flag = true;
	for (int u = 0; u < n; ++u)
	{
		if (!flag)
			break;
		if (color[u] == 0)
			DFS_visit(n, u, color, matrix, flag);
	}
	if (flag)
		return true;
	else
		return false;
}

int main()
{
	int n;
	cin >> n;
	vector <vector<int> > graph(n);
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
		{
			int e;
			cin >> e;
			graph[i].push_back(e);
		}
	vector <int> color(n, 0);
	bool flag = DFS(n, color, graph);
	if (flag)
		cout << 0;
	else
		cout << 1;
	return 0;
}