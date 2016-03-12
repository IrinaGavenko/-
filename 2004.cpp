#include <iostream>
#include <queue>
#include <vector>
#include <climits>
using namespace std;

struct point
{
	int x;
	int y;
	point(){};
	point(int a, int b) :x(a), y(b){};
};

bool check(int x, int y, int n, int m)
{
	if (x >= 0 && x < n && y >= 0 && y < m)
		return true;
	else
		return false;
}
point move(point c, int command, vector<int>& dx, vector<int>& dy, vector<vector <bool> >& is_wall, int n, int m)
{
	int i = command;
	point _c = c;
	int l = 0;
	while (check(c.x + dx[i], c.y + dy[i], n, m) && !is_wall[c.x + dx[i]][c.y + dy[i]])
	{
		c.x += dx[i];
		c.y += dy[i];
		l++;
	}
	int r = (l + 1) / 2;
	c.x = _c.x + dx[i] * r;
	c.y = _c.y + dy[i] * r;
	return c;
}


void BFS(point start, vector<vector <int> >& distance_to, point finish, vector<int>& dx, vector<int>& dy, vector<vector <bool> >& is_wall, int n, int m)
{
	point c1, c2;
	queue<point> q;
	q.push(start);
	distance_to[start.x][start.y] = 0;
	while (!q.empty())
	{
		c1 = q.front();
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			c2 = move(c1, i, dx, dy, is_wall, n, m);
			if (distance_to[c2.x][c2.y] == -1)
			{
				distance_to[c2.x][c2.y] = distance_to[c1.x][c1.y] + 1;
				q.push(c2);
				if (c2.x == finish.x && c2.y == finish.y)
					return;
			}
		}
	}
}

int main()
{
	int n, m;
	cin >> n >> m;

	char c;
	vector<int> dx(4);
	dx[0] = 0; dx[1] = 1; dx[2] = 0; dx[3] = -1;
	vector<int> dy(4);
	dy[0] = 1; dy[1] = 0; dy[2] = -1; dy[3] = 0;

	point start, finish;
	vector<vector<bool> > is_wall;
	vector <vector <int> > distance_to(30, vector <int>(30));
	is_wall = vector<vector<bool> >(n + 1, vector<bool>(m + 1));

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
		{
			cin >> c;
			if (c == 'S')
			{
				start.x = i;
				start.y = j;
			}
			if (c == '#')
				is_wall[i][j] = true;
			if (c == 'T')
			{
				finish.x = i;
				finish.y = j;
			}
			if (c == '.')
				is_wall[i][j] = false;
		}

	for (int i = 0; i <= 20; i++)
		for (int j = 0; j <= 20; j++)
			distance_to[i][j] = -1;

	BFS(start, distance_to, finish, dx, dy, is_wall, n, m);
	cout << distance_to[finish.x][finish.y] << endl;
	return 0;
}
