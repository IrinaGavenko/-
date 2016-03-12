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
	string str = str2 + '#' + str1;

	vector<int> p = prefix_function(str);
	for (int i = 0; i < p.size(); ++i)
		if (p[i] == str2.length())
			cout << i - 2 * str2.length() << ' ';
	return 0;
}