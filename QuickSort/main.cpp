#include "QuickSort.hpp"
#include <iostream>
#include <algorithm>    // std::sort
#include <vector> 
bool myfunction(int i, int j) { return (i < j); }

struct myclass {
	bool operator() (int i, int j) { return (i < j); }
} myobject;
class Cmp {
private:
	int number;
public:
	Cmp() {
		number = 0;
	}
	inline int get() const {
		return number;
	}
};
bool operator>(const Cmp& first, const Cmp& second) {
	return first.get() > second.get();
}
template<typename T>
std::vector<T> create_rand_and_quicksort(std::vector<T>* input)
{
	for (int i = 0; i < 100; ++i) {
		(*input).push_back(rand());
	}
	std::vector<T> res = *input;
	quick_sort::sort(res.begin(), res.end());
	return res;
}
int main() {
	std::vector<int> myvector;
	std::vector<int> my_sort_res;
	std::vector<int> std_sort_res;
	my_sort_res = create_rand_and_quicksort(&myvector);
	std_sort_res = myvector;
	std::sort(std_sort_res.begin(), std_sort_res.end());
	return 0;
}