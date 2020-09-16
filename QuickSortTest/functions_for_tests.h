#pragma once
#include "pch.h"
#include "QuickSort.hpp"

template<typename T>
void my_and_std_sort_result(const T my_sort_res, const T std_sort_res, const T end) {
	auto i = my_sort_res;
	for (auto j = std_sort_res; j != end; ++j) {
		ASSERT_TRUE(i == j);
		++i;
	}
}
template<typename T, typename type>
T create_rand_and_quicksort(T* input)
{
	for (int i = 0; i < 100; ++i) {
		(*input).push_back(static_cast<type>(static_cast<double>(rand()) / RAND_MAX * 1000));
	}
	T res = *input;
	quick_sort::sort(res.begin(), res.end());
	return res;
}
template<typename T>
void test_empty_container() {
	T myvector;
	T my_sort_res;
	T std_sort_res;
	std_sort_res = myvector;
	quick_sort::sort(my_sort_res.begin(), my_sort_res.end());
	std::sort(std_sort_res.begin(), std_sort_res.end());
	my_and_std_sort_result(my_sort_res.begin(), std_sort_res.end(), std_sort_res.end());
}
template<typename T>
void test_rand_numb() {
	T myvector;
	T my_sort_res;
	T std_sort_res;
	my_sort_res = create_rand_and_quicksort<T, T::value_type>(&myvector);
	std_sort_res = myvector;
	std::sort(std_sort_res.begin(), std_sort_res.end());
	my_and_std_sort_result(my_sort_res.begin(), std_sort_res.end(), std_sort_res.end());
}
template<typename T>
void test_all_equal_numbs() {
	T myvector;
	T my_sort_res;
	T std_sort_res;
	std_sort_res = myvector;
	for (int i = 100; i > 0; --i) {
		myvector.push_back(0);
	}
	my_sort_res = myvector;
	std_sort_res = myvector;
	quick_sort::sort(my_sort_res.begin(), my_sort_res.end());
	std::sort(std_sort_res.begin(), std_sort_res.end());
	my_and_std_sort_result(my_sort_res.begin(), std_sort_res.end(), std_sort_res.end());
}
template<typename T>
void test_reverse_sorted_numbs() {
	T myvector;
	T my_sort_res;
	T std_sort_res;
	std_sort_res = myvector;
	for (int i = 100; i > 0; --i) {
		myvector.push_back(i);
	}
	my_sort_res = myvector;
	std_sort_res = myvector;
	quick_sort::sort(my_sort_res.begin(), my_sort_res.end());
	std::sort(std_sort_res.begin(), std_sort_res.end());
	my_and_std_sort_result(my_sort_res.begin(), std_sort_res.end(), std_sort_res.end());
}
template<typename T>
void test_already_sorted_numbs() {
	T myvector;
	T my_sort_res;
	T std_sort_res;
	std_sort_res = myvector;
	for (int i = 0; i < 100; ++i) {
		myvector.push_back(i);
	}
	my_sort_res = myvector;
	std_sort_res = myvector;
	quick_sort::sort(my_sort_res.begin(), my_sort_res.end());
	std::sort(std_sort_res.begin(), std_sort_res.end());
	my_and_std_sort_result(my_sort_res.begin(), std_sort_res.end(), std_sort_res.end());
}
template<typename T>
void test() {
	using typeS = T::value_type;
	test_rand_numb<T>();
	test_empty_container<T>();
	test_all_equal_numbs<T>();
	test_already_sorted_numbs<T>();
	test_reverse_sorted_numbs<T>();
}

template<typename T>
T* create_rand_and_quicksort_for_array(T*& input)
{
	input = new T[100];
	T* res = new T[100];
	for (int i = 0; i < 100; ++i) {
		res[i] = input[i] = (static_cast<T>(static_cast<double>(rand()) / RAND_MAX * 1000));
	}
	quick_sort::sort(&res[0], &res[100]);
	return res;
}
template<typename T>
void my_and_std_sort_result_for_array(const T my_sort_res, const T std_sort_res, size_t size_of_array) {
	for (int i = 0; i < size_of_array; ++i) {
		ASSERT_TRUE(my_sort_res[i] == std_sort_res[i]);
	}
}
template<typename T>
void array_test_rand_numb() {
	T* myvector = nullptr;
	T* my_sort_res = nullptr;
	T* std_sort_res = nullptr;
	my_sort_res = create_rand_and_quicksort_for_array(myvector);
	std_sort_res = new T[100];
	memcpy(std_sort_res, myvector, 100 * sizeof(T));
	std::sort(&std_sort_res[0], &std_sort_res[100]);
	my_and_std_sort_result_for_array(my_sort_res, std_sort_res, 100);
	delete myvector;
	delete my_sort_res;
	delete std_sort_res;
}
template<typename T>
void array_test_empty_array() {
	T* myvector = nullptr;
	T* my_sort_res = nullptr;
	T* std_sort_res = nullptr;
	quick_sort::sort(&my_sort_res, &my_sort_res);
	std::sort(&std_sort_res, &std_sort_res);
	my_and_std_sort_result_for_array(my_sort_res, std_sort_res, 0);
}
template<typename T>
void array_test_reverse_sorted_numbs() {
	T* myvector = new T[100];
	T* my_sort_res = new T[100];
	T* std_sort_res = new T[100];
	for (int i = 99; i >= 0; --i) {
		myvector[i] = i;
	}
	memcpy(my_sort_res, myvector, 100 * sizeof(T));
	memcpy(std_sort_res, myvector, 100 * sizeof(T));
	quick_sort::sort(&my_sort_res[0], &my_sort_res[100]);
	std::sort(&std_sort_res[0], &std_sort_res[100]);
	my_and_std_sort_result_for_array(my_sort_res, std_sort_res, 0);
	delete myvector;
	delete my_sort_res;
	delete std_sort_res;
}
template<typename T>
void array_test_all_equal_numbs() {
	T* myvector = new T[100];
	T* my_sort_res = new T[100];
	T* std_sort_res = new T[100];
	for (int i = 0; i < 100; ++i) {
		myvector[i] = 0;
	}
	memcpy(my_sort_res, myvector, 100 * sizeof(T));
	memcpy(std_sort_res, myvector, 100 * sizeof(T));
	quick_sort::sort(&my_sort_res[0], &my_sort_res[100]);
	std::sort(&std_sort_res[0], &std_sort_res[100]);
	my_and_std_sort_result_for_array(my_sort_res, std_sort_res, 0);
	delete myvector;
	delete my_sort_res;
	delete std_sort_res;
}
template<typename T>
void array_test_already_sorted_numbs() {
	T* myvector = new T[100];
	T* my_sort_res = new T[100];
	T* std_sort_res = new T[100];
	for (int i = 0; i < 100; ++i) {
		myvector[i] = i;
	}
	memcpy(my_sort_res, myvector, 100 * sizeof(T));
	memcpy(std_sort_res, myvector, 100 * sizeof(T));
	quick_sort::sort(&my_sort_res[0], &my_sort_res[100]);
	std::sort(&std_sort_res[0], &std_sort_res[100]);
	my_and_std_sort_result_for_array(my_sort_res, std_sort_res, 0);
	delete std_sort_res;
	delete my_sort_res;
	delete myvector;
}
template<typename T>
void array_test() {
	array_test_rand_numb<T>();
	array_test_empty_array<T>();
	array_test_all_equal_numbs<T>();
	array_test_already_sorted_numbs<T>();
	array_test_reverse_sorted_numbs<T>();
}