#include <iostream>
#include <vector>
using namespace std;

class Treap
{
public:

	int key;
	int priority;
	Treap* left;
	Treap* right;

	Treap(int _x = 0, int _y = 0)
	{
		key = _x;
		priority = _y;
		left = NULL;
		right = NULL;
	}
};

void split(Treap* T, int x, Treap* & L, Treap* & R)
{
	if (T == NULL)
	{
		L = NULL;
		R = NULL;
	}
	else if (T->key < x)
	{
		split(T->right, x, T->right, R);
		L = T;
	}
	else
	{
		split(T->left, x, L, T->left);
		R = T;
	}
}

void merge(Treap* L, Treap* R, Treap* & T)
{
	if (L == NULL || R == NULL)
		if (!L)
			T = R;
		else
			T = L;
	else if (L->priority > R->priority)
	{
		merge(L->right, R, L->right);
		T = L;
	}
	else
	{
		merge(L, R->left, R->left);
		T = R;
	}
}

int find(Treap* T, int x)
{
	if (T->key == x)
		return T->key;
	else if (T->key > x)
	{
		if (T->left == NULL)
			return T->key;
		else
		{
			int answer = find(T->left, x);
			if (answer == -1)
				return T->key;
			else
				return answer;
		}
	}
	else
	{
		if (T->right == NULL)
			return -1;
		return find(T->right, x);
	}
}

void insert(Treap* & T, int x)
{
	Treap* L = NULL; Treap* L2 = NULL; Treap* L3 = NULL; Treap* R = NULL;
	Treap* _element = new Treap(x, rand());
	split(T, x, L, R);
	merge(L, _element, L2);
	merge(L2, R, L3);
	T = L3;
}

int main()
{
	int n;
	cin >> n;

	int key;
	char comand;
	char last_comand = '+';
	int last_value = 0;

	Treap* T = new Treap;

	for (int i = 0; i < n; i++)
	{
		cin >> comand;
		if (comand == '+')
		{
			cin >> key;
			if (last_comand == '+')
				insert(T, key);
			else
				insert(T, (key + last_value) % 1000000000);
			last_comand = '+';
		}
		else
		{
			last_comand = '?';
			cin >> key;
			int answer = find(T, key);
			last_value = answer;
			cout << answer << endl;
		}
	}
	return 0;
}