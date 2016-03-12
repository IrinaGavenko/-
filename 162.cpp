#include <iostream>
#include <queue>
using namespace std;


int distance_to[9][9][9][9];
struct point
{
	int x;
	int y;
	point(int a = 0, int b = 0)
	{
		x = a;
		y = b;
	}
};
bool check(int x, int y)
{
	if (x > 0 && x <= 8 && y > 0 && y <= 8)
		return true;
	else
		return false;
}

void BFS(int x1, int y1, int x2, int y2, vector <int>& dx, vector <int>& dy, queue<pair<point, point> > q)
{
	q.push(make_pair(point(x1, y1), point(x2, y2)));
	distance_to[x1][y1][x2][y2] = 0;
	while (q.size() > 0)
	{
		point c1, c2;
		int _x1, _x2, _y1, _y2;
		c1 = q.front().first;
		c2 = q.front().second;
		x1 = c1.x;
		x2 = c2.x;
		y1 = c1.y;
		y2 = c2.y;
		q.pop();
		if (x1 == x2 && y1 == y2)
		{
			cout << distance_to[x1][y1][x2][y2];
			exit(0);
		}
		for (int i = 0; i < 8; i++)
		{
			_x1 = x1 + dx[i];
			_y1 = y1 + dy[i];
			if (check(_x1, _y1))
			{
				for (int j = 0; j < 8; j++)
				{
					_x2 = x2 + dx[j];
					_y2 = y2 + dy[j];
					if (check(_x2, _y2) && distance_to[_x1][_y1][_x2][_y2] == 0)
					{
						distance_to[_x1][_y1][_x2][_y2] = distance_to[x1][y1][x2][y2] + 1;
						q.push(make_pair(point(_x1, _y1), point(_x2, _y2)));
					}
				}
			}
		}
	}

}
int main()
{
	vector <int> dx(8);
	dx[0] = 2; dx[1] = 2; dx[2] = 1; dx[3] = 1; dx[4] = -1; dx[5] = -1; dx[6] = -2; dx[7] = -2;
	vector <int> dy(8);
	dy[0] = 1; dy[1] = -1; dy[2] = 2; dy[3] = -2; dy[4] = 2; dy[5] = -2; dy[6] = 1; dy[7] = -1;

	queue<pair<point, point> > q;
	char a1, a2;
	int x1, x2, y1, y2;
	cin >> a1 >> y1 >> a2 >> y2;
	x1 = a1 - 'a' + 1;
	x2 = a2 - 'a' + 1;
	BFS(x1, y1, x2, y2, dx, dy, q);
	cout << -1;
	return 0;
}