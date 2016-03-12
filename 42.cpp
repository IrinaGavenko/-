#include <iostream>
#include <vector>
#include <stack>
using namespace std;

void DFS_visit(int u, int n, vector<vector <int> >& e, vector <int>& color, stack <int>& st, int& _count)
{
	color[u] = 1;
	_count++;
	st.push(u);
	for (int v = 0; v < e[u].size(); ++v)
	{
		if (color[e[u][v]] == 0)
			DFS_visit(e[u][v], n, e, color, st, _count);
	}
	color[u] = 2;
}

void DFS(int n, vector <vector <int> >& e, vector <int>& color, int& count, stack <int>& st_count, stack <int>& st)
{
	for (int v = 0; v < n; ++v)
		if (color[v] == 0)
		{
			count++;
			int _count = 0;
			DFS_visit(v, n, e, color, st, _count);
			st_count.push(_count);
		}
}

int main()
{
	int n, m;
	cin >> n >> m;
	int count = 0;
	vector <vector <int> > e(n);
	vector <int> color(n, 0);
	stack <int> st_count;
	stack <int> st;

	for (int i = 0; i < m; ++i)
	{
		int u, v;
		cin >> u >> v;
		u--; v--;
		e[u].push_back(v);
		e[v].push_back(u);
	}

	DFS(n, e, color, count, st_count, st);
	cout << count << endl;

	for (int i = 0; i < count; ++i)
	{
		cout << st_count.top() << endl;
		for (int j = 0; j < st_count.top(); ++j)
		{
			cout << st.top() + 1 << ' ';
			st.pop();
		}
		st_count.pop();
		cout << endl;
	}

	return 0;
}