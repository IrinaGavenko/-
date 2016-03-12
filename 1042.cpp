#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<int> build_z_function(string& s)
{
	int n = s.length();
	vector<int> z(n);
	int l = 0, r = 0;
	for (int i = 1; i < n; ++i)
	{
		if (i <= r)
			z[i] = min(r - i + 1, z[i - l]);
		while (i + z[i] < n && s[z[i]] == s[i + z[i]])
			++z[i];
		if (i + z[i] - 1 > r)
			l = i, r = i + z[i] - 1;
	}
	return z;
}

int main()
{

	string str;
	cin >> str;

	vector<int> z = build_z_function(str);
	z[0] = z.size();
	for (int i = 0; i < z.size(); ++i)
		cout << z[i] << ' ';

	return 0;
}
