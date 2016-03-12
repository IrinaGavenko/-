#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

vector<int> zFunction(string & s)
{
	int n = s.length();
	vector<int> z(n, 0);
	z[0] = n;
	int l = 0, r = 0;
	int j;
	for (int i = 1; i < n; i++)
	{
		if (i > r)
		{
			for (j = 0; ((j + i) < n) && (s[i + j] == s[j]); j++);
			z[i] = j;
			l = i;
			r = (i + j - 1);
		}
		else
		{
			if (z[i - l] < (r - i + 1))
				z[i] = z[i - l];
			else
			{
				for (j = 1; ((j + r) < n) && (s[r + j] == s[r - i + j]); j++);
				z[i] = (r - i + j);
				l = i;
				r = (r + j - 1);
			}
		}
	}
	return z;
}
vector<int> aFunction(string & s)
{
	string _str = s;
	reverse(_str.begin(), _str.end());
	_str = s + _str;
	vector<int> z = zFunction(_str);
	reverse(z.begin(), z.end());
	z.erase(z.begin() + s.size(), z.end());
	return z;
}


int main()
{
	int n;
	cin >> n;
	string s;
	cin >> s;
	vector<int> z = aFunction(s);
	for (int i = 0; i < n; ++i)
		cout << z[i] << ' ';
	return 0;
}