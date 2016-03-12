#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

long long int find_size(long long int n)
{
	long long int _n = 1;
	long long int c = n;
	while (_n < n)
		_n = (_n << 1);
	return _n;
}

vector<long long int> build_tree(long long int n, long long int size, vector<long long int>& tree)
{
	vector<long long int> v(2 * n, 0);

	for (long long int i = n; i < n + size; ++i)
		v[i] = tree[i - n];

	for (long long int i = n - 1; i > 0; i--)
		v[i] = v[2 * i] + v[2 * i + 1];

	return v;
}
void update(long long int id, long long int value, long long int n, vector<int long long>& t)
{
	id += n - 1;
	t[id] = value;

	while (id /= 2)
		t[id] = t[2 * id] + t[2 * id + 1];
}
long long int sum(long long int l, long long int r, long long int n, vector<long long int>& t)
{
	long long int answer = 0;
	l += n - 1;
	r += n - 1;

	while (l <= r)
	{
		if (l % 2 == 1)
			answer = answer + t[l];
		if (r % 2 == 0)
			answer = answer + t[r];

		l = (l + 1) / 2;
		r = (r - 1) / 2;
	}
	return answer;
}

int main()
{
	long long int n;
	cin >> n;
	vector<long long int> t(n, 0);
	for (long long int i = 0; i < n; ++i)
		cin >> t[i];
	long long int s = find_size(n);
	vector<long long int> tree = build_tree(s, n, t);
	n = s;

	long long int m;
	cin >> m;
	for (long long int i = 0; i < m; i++)
	{
		string comand;
		cin >> comand;
		if (comand == "s")
		{
			long long int id_l, id_r;
			cin >> id_l >> id_r;
			long long int answer = sum(id_l, id_r, n, tree);
			cout << answer << ' ';
		}
		if (comand == "u")
		{
			long long int id, value;
			cin >> id >> value;
			update(id, value, n, tree);
		}
	}
	return 0;
}