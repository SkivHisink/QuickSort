#include "QuickSort.hpp"
#include <iostream>
#include <algorithm>  
#include <vector> 

template<typename T>
std::vector<T> create_rand_and_quicksort(std::vector<T>& input)
{
	for (int i = 0; i < 1000; ++i) {
		input.push_back(rand());
	}
	std::vector<T> res = input;
	QuickSort::sort(res.begin(), res.end());
	return res;
}
int main() {
	std::vector<int> input;
	auto result = create_rand_and_quicksort(input);
	auto expected = input;
	std::sort(expected.begin(), expected.end());
	for (auto i = 0; i < result.size(); ++i) {
		if (result[i] != expected[i]) {
			std::cout << result[i] << "!=" << expected[i] << std::endl << "Sort work wrong" << std::endl;
		}
	}
	return 0;
}