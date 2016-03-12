#include <iostream>
#include <stack>
#include <queue>
#include <climits>
using namespace std;

class BFS_matrix
{

private:
	int n, m;
	int **color;
	int **matrix;
	int **distance;

public:
	BFS_matrix(int _n, int _m)
	{
		n = _n;
		m = _m;
		matrix = new int*[n];
		distance = new int*[n];
		color = new int*[n];
		for (int i = 0; i < n; i++)
		{
			matrix[i] = new int[m];
			distance[i] = new int[m];
			color[i] = new int[m];
		}
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
			{
				distance[i][j] = INT_MAX;;
				color[i][j] = 0;
				cin >> matrix[i][j];
			}
	}
	~BFS_matrix()
	{
		for (int i = 0; i < n; i++)
		{
			delete[] matrix[i];
			delete[] distance[i];
			delete[] color[i];
		}
		delete[] matrix;
		delete[] color;
		delete[] distance;
	}
	void BFS()
	{
		queue <pair<int, int> > queue;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				if (matrix[i][j] == 1)
				{
					distance[i][j] = 0;
					queue.push(make_pair(i, j));
					color[i][j] = 1;
				}

		while (!queue.empty())
		{
			pair<int, int> _pr = queue.front();

			queue.pop();
			for (int i = -1; i <= 1; i = i + 2)
				if (_pr.first + i >= 0 && _pr.first + i < n && color[_pr.first + i][_pr.second] == 0)
				{
					distance[_pr.first + i][_pr.second] = min(distance[_pr.first][_pr.second] + 1, distance[_pr.first + i][_pr.second]);
					queue.push(make_pair(_pr.first + i, _pr.second));
				}
			for (int j = -1; j <= 1; j = j + 2)
				if (_pr.second + j >= 0 && _pr.second + j < m && color[_pr.first][_pr.second + j] == 0)
				{
					distance[_pr.first][_pr.second + j] = min(distance[_pr.first][_pr.second] + 1, distance[_pr.first][_pr.second + j]);
					queue.push(make_pair(_pr.first, _pr.second + j));
				}

			color[_pr.first][_pr.second] = 2;
		}
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
				cout << distance[i][j] << " ";
			cout << endl;
		}

	}


};

int main()
{
	int n, m;
	cin >> n >> m;
	BFS_matrix graph(n, m);
	graph.BFS();
	return 0;
}