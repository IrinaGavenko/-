#include <iostream>
#include <stack>
#include <vector>
#include <set>
using namespace std;

class graph
{
private:
	vector<int> number;
	vector<int> parents;
	set<int> have;
public:
	stack <int> play_game(int a, int b)
	{
		number.reserve(1000000);
		parents.reserve(1000000);
		int position = -1;
		int i = 0;
		int k = 0;
		number.push_back(a);
		if (a == b)
			position = 0;
		parents.push_back(-1);
		while (position == -1)
		{
			int s = 0;
			if (number[i] / 1000 != 9 && have.find(number[i] + 1000) == have.end())
			{
				++s;
				number.push_back(number[i] + 1000);
				have.insert(number[i] + 1000);
			}
			if (number[i] % 10 != 1 && have.find(number[i] - 1) == have.end())
			{
				++s;
				number.push_back(number[i] - 1);
				have.insert(number[i] - 1);
			}
			int x = (number[i] * 10) / 10000 + (number[i] % 1000) * 10;
			if (have.find(x) == have.end())
			{
				++s;
				number.push_back(x);
				have.insert(x);
			}
			int y = (number[i] % 10) * 1000 + number[i] / 10;
			if (have.find(y) == have.end())
			{
				s++;
				number.push_back(y);
				have.insert(y);
			}
			for (int j = 1; j < s + 1; j++)
			{
				parents.push_back(i);
				if (number[k + j] == b)
				{
					position = k + j;
					break;
				}
			}
			i++;
			k = k + s;

		}
		stack<int> path;
		while (position != -1)
		{
			path.push(number[position]);
			position = parents[position];
		}
		return path;
	}
};

int main()
{
	graph G;
	int a, b;
	cin >> a >> b;
	stack <int> path = G.play_game(a, b);
	while (!path.empty())
	{
		cout << path.top() << endl;
		path.pop();
	}
	return 0;
}