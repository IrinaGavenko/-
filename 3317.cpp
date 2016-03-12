#include <iostream>
#include <vector>

using namespace std;

void build_tree(long long int n, vector<long long int>& data, vector<long long int>& tree)
{
	for (long long int i = 1; i <= n; ++i)
	{
		long long int id = i;
		while (id <= n)
		{
			tree[id] += data[i];
			id = (id | (id + 1));
		}
	}
}
void update(long long int id, long long int new_value, vector<long long int>& tree, vector<long long int>& data, long long int n)
{
	long long int old_value = data[id];
	data[id] = new_value;
	while (id <= n)
	{
		tree[id] = tree[id] - old_value + new_value;
		id = (id | (id + 1));
	}
}
long long int sum(long long int id, vector<long long int>& tree)
{
	long long int result = 0;
	while (id >= 0)
	{
		result += tree[id];
		id = (id & (id + 1)) - 1;
	}
	return result;
}

int main()
{
	long long int n;
	cin >> n;

	vector<long long int> data(n + 1, 0);
	vector<long long int> tree(n + 1, 0);

	for (long long int i = 1; i <= n; ++i)
		cin >> data[i];

	build_tree(n, data, tree);

	long long int m;
	cin >> m;

	for (long long int i = 0; i < m; ++i)
	{
		char comand;
		cin >> comand;
		if (comand == 'u')
		{
			long long int id, value;
			cin >> id >> value;
			update(id, value, tree, data, n);
		}
		if (comand == 's')
		{
			long long int id_l, id_r;
			cin >> id_l >> id_r;
			id_l--;
			cout << (sum(id_r, tree) - sum(id_l, tree)) << ' ';
		}
	}

	return 0;
}