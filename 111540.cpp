#include <iostream>
#include <vector>

using namespace std;

void DFS_visit(int u, int n, vector <vector <int> >& e, vector<int>& color, vector<int>& id, int parity, bool& flag)
{
	color[u] = 1;
	if (parity == 1)
		id[u] = 2;
	else
		id[u] = 1;

	for (int v = 0; v < e[u].size(); ++v)
	{
		if (color[e[u][v]] != 0)
		{
			if (((id[e[u][v]] == 1) && (id[u] == 1)) || ((id[e[u][v]] == 2) && (id[u] == 2)))
			{
				flag = false;
				return;
			}
		}
		if (color[e[u][v]] == 0)
		{
			DFS_visit(e[u][v], n, e, color, id, id[u], flag);
		}
	}
	color[u] = 2;
}

bool DFS(int n, vector <vector <int> >& e, vector<int>& color, vector<int>& id)
{
	bool flag = true;
	for (int u = 0; u < n; ++u)
	{
		if (flag == false)
			return false;
		if (color[u] == 0)
		{
			DFS_visit(u, n, e, color, id, 2, flag);
		}
	}
	return true;
}

int main()
{
	int n, m;
	cin >> n >> m;
	vector <vector <int> > e(n);
	vector <int> color(n, 0);
	vector <int> id(n, 0);

	for (int i = 0; i < m; ++i)
	{
		int u, v;
		cin >> u >> v;
		u--; v--;
		e[u].push_back(v);
		e[v].push_back(u);
	}

	bool flag = DFS(n, e, color, id);
	if (flag)
		cout << "YES";
	else
		cout << "NO";
	return 0;
}