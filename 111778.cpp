#include <iostream>
#include <vector>
#include <string>

using namespace std;


int sum(int x, int y, vector<vector<int> >& t)
{
	int result = 0;
	for (int i = x; i >= 0; i = (i & (i + 1)) - 1)
		for (int j = y; j >= 0; j = (j & (j + 1)) - 1)
			result += t[i][j];
	return result;
}

void update(int x, int y, int value, vector<vector<int> >& t, int n)
{
	for (int i = x; i <= n; i = (i | (i + 1)))
		for (int j = y; j <= n; j = (j | (j + 1)))
			t[i][j] += value;
}


int main()
{
	int k, n;
	cin >> k >> n;
	vector<vector<int> > t(2 * n, vector<int>(2 * n, 0));

	int comand;
	cin >> comand;
	while (comand != 3)
	{
		if (comand == 1)
		{
			int x, y, val;
			cin >> x >> y >> val;
			x++; y++;
			update(x, y, val, t, n);
		}
		if (comand == 2)
		{
			int x1, y1, x2, y2;
			cin >> x1 >> y1 >> x2 >> y2;
			x1++; y1++; x2++; y2++;
			int answer = sum(x2, y2, t) + sum(x1 - 1, y1 - 1, t) - sum(x2, y1 - 1, t) - sum(x1 - 1, y2, t);
			cout << answer << endl;
		}
		cin >> comand;
	}

	return 0;
}