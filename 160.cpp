#include <iostream>
#include <queue>
#include <vector>
#include <climits>
using namespace std;

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

int dx[] = { 2, 2, 1, 1, -1, -1, -2, -2 };
int dy[] = { 1, -1, 2, -2, 2, -2, 1, -1 };
queue<point> my_queue;
vector<vector<int> > distance_to;
vector<vector<point> > parent;
int n;


bool check(int x, int y)
{
	if (x > 0 && x <= n && y > 0 && y <= n) return true;
	else return false;
}

void show_parent(point a)
{
	if (a.x != 0 && a.y != 0)
	{
		show_parent(parent[a.x][a.y]);
		cout << a.x << " " << a.y << endl;
	}
}

void bfs(int x1, int y1, int x2, int y2)
{
	distance_to[x1][y1] = 0;
	my_queue.push(point(x1, y1));
	while (my_queue.size() > 0)
	{
		point source = my_queue.front();
		my_queue.pop();
		if (source.x == x2 && source.y == y2)
		{
			cout << distance_to[source.x][source.y] << endl;
			show_parent(source);
			return;
		}
		for (int i = 0; i < 8; i++)
		{
			if (check(source.x + dx[i], source.y + dy[i]) && distance_to[source.x + dx[i]][source.y + dy[i]] == INT_MAX)
			{
				distance_to[source.x + dx[i]][source.y + dy[i]] = distance_to[source.x][source.y] + 1;
				parent[source.x + dx[i]][source.y + dy[i]] = source;
				my_queue.push(point(source.x + dx[i], source.y + dy[i]));
			}
		}
	}
}

int main()
{

	cin >> n;
	int x1, x2, y1, y2;
	cin >> x1 >> y1 >> x2 >> y2;
	distance_to = vector<vector<int> >(n + 1, vector<int>(n + 1, INT_MAX));
	parent = vector<vector<point> >(n + 1, vector<point>(n + 1, 0));
	if (x1 == x2 && y1 == y2)
		cout << 0;
	else
		bfs(x1, y1, x2, y2);
	return 0;
}

