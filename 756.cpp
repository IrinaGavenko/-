#include <iostream>
#include <vector>
using namespace std;

template<class T> class Heap
{
	vector<T> heap;
	int parent(int i)
	{
		return ((i - 1) / 2);
	}
	int left(int i)
	{
		return (2 * i + 1);
	}
	int right(int i)
	{
		return (2 * i + 2);
	}
	void sift_down(int i)
	{
		int L, R, largest;
		L = left(i);
		R = right(i);
		if (L <= (heap.size() - 1) && (heap[L] <= heap[i]))
			largest = L;
		else
			largest = i;
		if (R <= (heap.size() - 1) && (heap[R] <= heap[largest]))
			largest = R;
		if (largest != i)
		{
			swap(heap[i], heap[largest]);
			sift_down(largest);
		}
	}
	void sift_up(int i)
	{
		T x;
		while (i > 0 && (heap[i] <= heap[parent(i)]))
		{
			x = heap[i];
			heap[i] = heap[parent(i)];
			i = parent(i);
			heap[i] = x;
		}
	}
	void build()
	{
		int n = heap.size();
		for (int i = ((n - 1) / 2); i >= 0; i--)
		{
			sift_down(i);
		}
	}

public:
	Heap(){};
	Heap(T * array, int n)
	{
		for (int i = 0; i < n; i++)
		{
			heap.push_back(array[i]);
		}
		this->heap.build();

	}
	void Insert(T value)
	{
		heap.push_back(value);
		sift_up(heap.size() - 1);
	}
	T extract_max()
	{
		T max;
		max = heap[0];
		heap.at(0) = heap[heap.size() - 1];
		heap.pop_back();
		if (heap.size() != 0)
			sift_down(0);
		return max;
	}
	T max()
	{
		return heap[0];
	}
	void heap_sort()
	{
		vector<T> _heap;
		while (heap.size() > 1)
		{
			swap(heap[0], heap[heap.size() - 1]);
			_heap.push_back(heap.back());
			heap.pop_back();
			this->heap.sift_down(0);
		}
		while (_heap.size() != 0)
		{
			heap.push_back(_heap.back());
			_heap.pop_back();
		}
	}
	void return_heap()
	{
		for (int i = 0; i < heap.size(); i++)
		{
			cout << this->heap[i] << " ";
		}
		cout << endl;
	}
};



int main()
{
	int n, k;
	int value;
	cin >> n >> k;
	Heap< pair<int, int> > heap;

	for (int i = 0; i < n; i++)
	{
		cin >> value;
		heap.Insert(pair<int, int>(value, i));
		if (i - heap.max().second > k - 1)
		{
			while (i - heap.max().second > k - 1)
				heap.extract_max();
			cout << (heap.max()).first << endl;
		}
		else
			if (i >= k - 1)
				cout << (heap.max()).first << endl;

	}
	return 0;
}

