#include "pch.h"
#include <vector>
#include <deque>
#include "functions_for_tests.h"

TEST(TestCaseName, TestName) {
	EXPECT_EQ(1, 1);
	EXPECT_TRUE(true);
}
//
TEST(VectorContainerTest, IntType) {
	test<std::vector<int>>();
}
TEST(VectorContainerTest, UIntType) {
	test<std::vector<unsigned int>>();
}
TEST(VectorContainerTest, FloatType) {
	test<std::vector<float>>();
}
TEST(VectorContainerTest, DoubleType) {
	test<std::vector<double>>();
}
TEST(VectorContainerTest, LongType) {
	test<std::vector<long>>();
}
TEST(VectorContainerTest, ULongType) {
	test<std::vector<unsigned long>>();
}
TEST(VectorContainerTest, CharType) {
	test<std::vector<char>>();
}
TEST(VectorContainerTest, UCharType) {
	test<std::vector<unsigned char>>();
}
//
TEST(DectorContainerTest, IntType) {
	test<std::deque<int>>();
}
TEST(DequeContainerTest, UIntType) {
	test<std::deque<unsigned int>>();
}
TEST(DequeContainerTest, FloatType) {
	test<std::deque<float>>();
}
TEST(DequeContainerTest, DoubleType) {
	test<std::deque<double>>();
}
TEST(DequeContainerTest, LongType) {
	test<std::deque<long>>();
}
TEST(DequeContainerTest, ULongType) {
	test<std::deque<unsigned long>>();
}
TEST(DequeContainerTest, CharType) {
	test<std::deque<char>>();
}
TEST(DequeContainerTest, UCharType) {
	test<std::deque<unsigned char>>();
}
//
TEST(StringContainerTest, CharType) {
	_CrtMemState startPoint, endPoint, diff;
	_CrtMemCheckpoint(&startPoint); {
		test<std::string>();
	}_CrtMemCheckpoint(&endPoint);
	ASSERT_EQ(0, _CrtMemDifference(&diff, &startPoint, &endPoint)) << "Memory leaks detected";
}
//
TEST(ArrayContainerTest, IntType) {
	_CrtMemState startPoint, endPoint, diff;
	_CrtMemCheckpoint(&startPoint); {
		array_test<int>();
	}_CrtMemCheckpoint(&endPoint);
	ASSERT_EQ(0, _CrtMemDifference(&diff, &startPoint, &endPoint)) << "Memory leaks detected";
}
TEST(ArrayContainerTest, UIntType) {
	_CrtMemState startPoint, endPoint, diff;
	_CrtMemCheckpoint(&startPoint); {
		array_test<unsigned int>();
	}_CrtMemCheckpoint(&endPoint);
	ASSERT_EQ(0, _CrtMemDifference(&diff, &startPoint, &endPoint)) << "Memory leaks detected";
}
TEST(ArrayContainerTest, FloatType) {
	_CrtMemState startPoint, endPoint, diff;
	_CrtMemCheckpoint(&startPoint); {
		array_test<float>();
	}_CrtMemCheckpoint(&endPoint);
	ASSERT_EQ(0, _CrtMemDifference(&diff, &startPoint, &endPoint)) << "Memory leaks detected";
}
TEST(ArrayContainerTest, DoubleType) {
	_CrtMemState startPoint, endPoint, diff;
	_CrtMemCheckpoint(&startPoint); {
		array_test<double>();
	}_CrtMemCheckpoint(&endPoint);
	ASSERT_EQ(0, _CrtMemDifference(&diff, &startPoint, &endPoint)) << "Memory leaks detected";
}
TEST(ArrayContainerTest, LongType) {
	_CrtMemState startPoint, endPoint, diff;
	_CrtMemCheckpoint(&startPoint); {
		array_test<long>();
	}_CrtMemCheckpoint(&endPoint);
	ASSERT_EQ(0, _CrtMemDifference(&diff, &startPoint, &endPoint)) << "Memory leaks detected";
}
TEST(ArrayContainerTest, ULongType) {
	_CrtMemState startPoint, endPoint, diff;
	_CrtMemCheckpoint(&startPoint); {
		array_test<unsigned long>();
	}_CrtMemCheckpoint(&endPoint);
	ASSERT_EQ(0, _CrtMemDifference(&diff, &startPoint, &endPoint)) << "Memory leaks detected";
}
TEST(ArrayContainerTest, CharType) {
	_CrtMemState startPoint, endPoint, diff;
	_CrtMemCheckpoint(&startPoint); {
		array_test<char>();
	}_CrtMemCheckpoint(&endPoint);
	ASSERT_EQ(0, _CrtMemDifference(&diff, &startPoint, &endPoint)) << "Memory leaks detected";
}
TEST(ArrayContainerTest, UCharType) {
	_CrtMemState startPoint, endPoint, diff;
	_CrtMemCheckpoint(&startPoint); {
		array_test<unsigned char>();
	}_CrtMemCheckpoint(&endPoint);
	ASSERT_EQ(0, _CrtMemDifference(&diff, &startPoint, &endPoint)) << "Memory leaks detected";
}
//
TEST(MainComparator, CompareVectorsSizes) {
	class comparator {
	public:
		bool operator() (int i, int j) { return (i < j); }
	};
	std::vector<int> array;
	for (int i = 0; i < 20; i++)
		array.push_back(rand());
	quick_sort::sort(array.begin(), array.end(), comparator());
	for (int i = 0; i < array.size() - 1; i++)
	{
		EXPECT_GT(array[i + 1], array[i]);
	}
}