#include <iostream>
#include <set>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>

using namespace std;

class element
{
public:
	int value;
	int p;
	int digit;
	vector<int> desc;
	element(int val, vector<int> &digits, int div, int prev = -1, int digit = -1) : value(val), p(prev), digit(digit)
	{
		for (int i = 0; i < digits.size(); ++i)
		{
			desc.push_back((val * 10 + digits[i]) % div);
		}
	}
	bool operator < (const element& other) const
	{
		return this->value < other.value;
	}
};


int main()
{
	string str;
	int k, _digits;

	cin >> str >> k >> _digits;

	vector<int> digits(_digits);

	for (int i = 0; i < _digits; ++i)
	{
		cin >> digits[i];
	}

	sort(digits.begin(), digits.end());

	set<element> used;
	deque<element> queue, answer;

	int remainder = 0;

	for (int i = 0; i < str.size(); ++i)
		remainder = (remainder * 10 + (str[i] - '0')) % k;

	if (remainder == 0)
	{
		cout << str;
		return 0;
	}

	queue.push_back(element(remainder, digits, k));

	while (queue.size())
	{
		element c = queue.front();
		queue.pop_front();

		used.insert(c);

		for (int i = 0; i < c.desc.size(); ++i)
		{
			element next(c.desc[i], digits, k, c.value, digits[i]);
			if (used.find(next) == used.end())
			{
				used.insert(next);
				queue.push_back(next);

				if (next.value == 0)
				{
					while (next.p != -1)
					{
						answer.push_front(next);
						next = *used.find(element(next.p, digits, k));
					}

					cout << str;

					for (deque<element>::iterator I = answer.begin(); I != answer.end(); ++I)
						cout << I->digit;

					return 0;
				}
			}
		}
	}

	cout << -1;

	return 0;
}