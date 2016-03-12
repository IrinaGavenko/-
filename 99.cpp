#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<int> prefix_function(string s)
{
	int n = s.length();
	vector<int> p(n, 0);
	for (int i = 1; i < n; ++i)
	{
		int j = p[i - 1];
		while (j > 0 && s[i] != s[j])
			j = p[j - 1];
		if (s[i] == s[j])
			++j;
		p[i] = j;
	}
	return p;
}

int main()
{
	string str1, str2;
	cin >> str1 >> str2;
	if (str1 == str2)
	{
		cout << 0;
		return 0;
	}
	string str = str2 + '#' + str1 + str1;

	vector<int> p = prefix_function(str);
	bool flag = false;
	for (int i = 0; i < p.size(); ++i)
		if (p[i] == str2.length())
		{
			cout << (str1.length() - (i - 2 * str2.length())) << ' ';
			flag = true;
			break;
		}
	if (flag == false)
		cout << -1;
	return 0;
}