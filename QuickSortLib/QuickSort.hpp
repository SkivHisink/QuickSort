#include <type_traits>
#include <iterator>
class QuickSort {
	QuickSort() = delete;
private:
	template<typename RandomAccessIterator>
	static int partition(const RandomAccessIterator first, const int low, const int high)
	{
		auto tmp = first;
		for (auto i = 0; i < high; ++i) {
			++tmp;
		}
		auto pivot = tmp;
		auto i = (low - 1);
		for (auto j = low; j <= high - 1; ++j) {
			if (first[j] <= *pivot) {
				++i;
				std::swap(first[i], first[j]);
			}
		}
		std::swap(first[i + 1], first[high]);
		return (i + 1);
	}
public:
	template<typename RandomAccessIterator, typename Compare = std_cmp>
	static	void Qsort(const RandomAccessIterator first, const int low, const int high, Compare comp = std_cmp())
	{
		if (low < high)
		{
			const int partition_indx = partition(first, low, high);
			Qsort(first, low, partition_indx - 1, comp);
			Qsort(first, partition_indx + 1, high, comp);
		}
	}
};
class std_cmp
{
public:
	template<typename T>
	static bool comp(const T& elem1, const T& elem2)
	{
		return elem1 > elem2;
	}
};
namespace quick_sort {
	template<class iter>
	using it_tag = typename std::iterator_traits<iter>::iterator_category;

	template <typename RandomAccessIterator, typename Compare = std_cmp,
		std::enable_if_t<std::is_base_of_v<std::random_access_iterator_tag, it_tag<RandomAccessIterator>>, int> = 0>
		void sort(RandomAccessIterator first, RandomAccessIterator last, Compare comp = std_cmp())
	{
		QuickSort::Qsort(first, 0, static_cast<int>(last - first) - 1, comp);
	}
}