#include <iostream>
#include <vector>
#include <stack>

using namespace std;

void DFS_visit(int u, int n, vector <vector <int> >& e, /*vector <int>&*/ int* color, stack <int>& result, bool& flag)
{
	color[u] = 1;
	for (int v = 0; v < e[u].size(); ++v)
	{
		if (color[e[u][v]] == 1)
		{
			flag = true;
			return;
		}
		if (color[e[u][v]] == 0)
			DFS_visit(e[u][v], n, e, color, result, flag);
	}
	color[u] = 2;
	result.push(u);
}

stack<int> DFS(int n, vector <vector <int> >& e, /*vector <int>&*/ int* color)
{
	stack <int> result;
	bool flag = false;
	for (int u = 0; u < n; ++u)
	{
		if (color[u] == 0)
			DFS_visit(u, n, e, color, result, flag);
		if (flag)
		{
			stack <int> _result;
			return _result;
		}
	}
	return result;
}

int main()
{
	int n, m;
	cin >> n >> m;
	vector <vector <int> > e(n);
	//vector <int> color(n, 0);
	int* color = new int[n];
	for (int i = 0; i < n; ++i)
		color[i] = 0;
	for (int i = 0; i < m; ++i)
	{
		int u, v;
		cin >> u >> v;
		u--; v--;
		e[u].push_back(v);
	}
	stack <int> result = DFS(n, e, color);
	if (result.empty())
	{
		cout << "No";
		return 0;
	}
	cout << "Yes" << endl;

	while (!result.empty())
	{
		cout << result.top() + 1 << ' ';
		result.pop();
	}
	return 0;
}