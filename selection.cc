#include <iostream>
#include <vector>
#include <limits>

int select_kth(std::vector<int> values, unsigned k)
{
	if (k == 0 || k > values.size()) {
		return std::numeric_limits<int>::min();
	}

	for (unsigned i = 0; i < k; ++i) {
		unsigned minIdx = i;
		auto minValue = values[minIdx];
		
		for (unsigned j = i+1; j < values.size(); ++j) {
			auto currValue = values[j];
			if (currValue < minValue) {
				minValue = currValue;
				minIdx = j;
			}
		}
		
		if (minIdx != i) {
			using namespace std;
			swap(values[minIdx], values[i]);
		}
	}

	return values[k-1];
}

template<typename Iterator>
Iterator partition(Iterator left, Iterator right, Iterator pivot)
{
	if (left >= right) return pivot;

	using namespace std;

	swap(*pivot, *right);
	
	Iterator cand = left;
	while (left < right) {
		if (*left < *right) {
			swap(*cand, *left);
			++cand;
		}
		++left;
	}

	swap(*cand, *right);
	return cand;
}

template<typename Iterator>
Iterator select_pivot(Iterator left, Iterator right)
{
	return right;
}

template<typename Iterator>
Iterator select_nth(Iterator left, Iterator right, unsigned n)
{
	while (left < right) {
		Iterator pivot = select_pivot(left, right);
		pivot = partition(left, right, pivot);
	
		std::ptrdiff_t dist = pivot - left + 1;
	
		if (dist == n) {
			return pivot;
		}
	
		if (dist < n) {
			//return select_nth(pivot + 1, right, n - dist);
			left = pivot + 1;
			n = n - dist;
		} else {
			right = pivot - 1;
		}
	}
	
	return left;
}

int main()
{
	int n;
	std::cin >> n;

	std::vector<int> values;
	values.reserve(n);
	for (unsigned i = 0; i < n; ++i) {
		int v;
		std::cin >> v;
		values.push_back(v);
	}

	int k;
	std::cin >> k;

	auto iter = select_nth(values.begin(), values.begin()+values.size()-1, k);

	std::cout << k << "th=" << *iter << std::endl;
	
	return 0;
}