#include <iostream>
#include <vector>
#include <deque>
using namespace std;

class graph
{
private:
	int size;
	int number;
	vector<vector<int> > matrix;
	deque<int> top_sort;
	vector<int> visited;
	vector<int> component;
public:
	graph(int n, int m)
	{
		size = n;
		visited = vector<int>(n);
		component = vector<int>(n);
		matrix = vector<vector<int> >(n);
		number = -1;
		for (int i = 0; i < n; i++)
			component[i] = -1;
		for (int i = 0; i < m; i++)
		{
			int a, b;
			cin >> a >> b;
			matrix[a - 1].push_back(b - 1);
		}
	}
	void transpose_matrix()
	{
		vector<vector<int> > copy_matrix(size);
		for (int i = 0; i < size; i++)
			for (vector<int>::iterator j = matrix[i].begin(); j != matrix[i].end(); j++)
				copy_matrix[*j].push_back(i);
		matrix = copy_matrix;
	}

	void DFS_visit(int u, int type, int number = 0)
	{
		if (!type)
		{
			visited[u] = true;
			for (vector<int>::iterator it = matrix[u].begin(); it != matrix[u].end(); it++)
				if (!visited[*it])
					DFS_visit(*it, 0);
			top_sort.push_front(u);
		}
		else
		{
			visited[u] = true;
			component[u] = number;
			for (vector<int>::iterator it = matrix[u].begin(); it != matrix[u].end(); it++)
				if (!visited[*it])
					DFS_visit(*it, 1, number);
		}
	}
	void DFS(int type)
	{
		if (!type)
		{
			for (int i = 0; i < size; i++)
				if (!visited[i])
					DFS_visit(i, 0);
		}
		else
		{
			for (deque<int>::iterator it = top_sort.begin(); it != top_sort.end(); it++)
			{
				if (!visited[*it])
				{
					number++;
					DFS_visit(*it, 1, number);
				}
			}
		}
	}
	void strongly_connected_components()
	{
		DFS(0);
		visited = vector<int>(size);
		transpose_matrix();
		DFS(1);
		transpose_matrix();
	}
	void write_number()
	{
		cout << number + 1 << endl;
		for (int i = 0; i < size; i++)
		{
			cout << component[i] + 1 << " ";
		}
	}

};

int main()
{
	int n, m;
	cin >> n >> m;
	graph graph(n, m);
	graph.strongly_connected_components();
	graph.write_number();
	return 0;
}