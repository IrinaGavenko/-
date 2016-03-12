#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> zFunction(vector<int>& data)
{
	vector<int> z(data.size(), 0);
	int left = 0, right = 0;

	z[0] = data.size();

	for (int i = 1; i < data.size(); ++i)
	{
		if (i <= right)
		{
			z[i] = min(right - i + 1, z[i - left]);
		}

		while (i + z[i] < data.size() && data[z[i]] == data[i + z[i]])
			++z[i];

		if (i + z[i] - 1 > right)
		{
			left = i;
			right = i + z[i] - 1;
		}
	}

	return z;
}


int main()
{
	int n, m;

	cin >> n >> m;

	int size = 2 * n + 1;
	vector<int> data(size);

	for (int i = 0; i < n; ++i)
	{
		cin >> data[i];
		data[2 * n - i] = data[i];
	}

	data[n] = -1;

	vector<int> z = zFunction(data);

	for (int i = n + 1; i < size; ++i)
		if (z[i] == size - i && ((size - i) % 2 == 0))
		{
			cout << n - (size - i) / 2 << ' ';
		}

	cout << n;

	return 0;
}