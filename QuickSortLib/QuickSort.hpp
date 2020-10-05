#include <type_traits>
#include <iterator>
class QuickSort {
	QuickSort() = delete;
	static const int MAX_DEPTH = 48;
public:
	template<typename RandomAccessIterator, typename Compare = std_cmp>
	static int Qsort(RandomAccessIterator begin, size_t elements, Compare comp = std_cmp())
	{
		size_t begin_pos_container[MAX_DEPTH], end_pos_container[MAX_DEPTH], left, right;
		int i = 0;
		begin_pos_container[0] = 0;
		end_pos_container[0] = elements;

		while (i >= 0) {
			left = begin_pos_container[i];
			right = end_pos_container[i];
			if (right - left > 1) {
				size_t middle = left + ((right - left) >> 1);
				auto piv = begin[middle];
				begin[middle] = begin[left];

				if (i == MAX_DEPTH - 1) {
					return -1;
				}
				--right;
				while (left < right) {
					while (begin[right] >= piv && left < right) {
						--right;
					}
					if (left < right)
						begin[left++] = begin[right]; {
						while (begin[left] <= piv && left < right)
							++left;
					}
					if (left < right) {
						begin[right--] = begin[left];
					}
				}
				begin[left] = piv;
				middle = left + 1;
				while (left > begin_pos_container[i] && begin[left - 1] == piv) {
					--left;
				}
				while (middle < end_pos_container[i] && begin[middle] == piv) {
					++middle;
				}
				if (left - begin_pos_container[i] > end_pos_container[i] - middle) {
					begin_pos_container[i + 1] = middle;
					end_pos_container[i + 1] = end_pos_container[i];
					end_pos_container[i++] = left;
				}
				else {
					begin_pos_container[i + 1] = begin_pos_container[i];
					end_pos_container[i + 1] = left;
					begin_pos_container[i++] = middle;
				}
			}
			else {
				--i;
			}
		}
		return 0;
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
		QuickSort::Qsort(first, static_cast<int>(last - first), comp);
	}
}
//private:
//	template<typename RandomAccessIterator>
//	static int partition(const RandomAccessIterator first, const int low, const int high)
//	{
//		auto tmp = first;
//		for (auto i = 0; i < high; ++i) {
//			++tmp;
//		}
//		auto pivot = tmp;
//		auto i = (low - 1);
//		for (auto j = low; j <= high - 1; ++j) {
//			if (first[j] <= *pivot) {
//				++i;
//				std::swap(first[i], first[j]);
//			}
//		}
//		std::swap(first[i + 1], first[high]);
//		return (i + 1);
//	}
//public:
//	template<typename RandomAccessIterator, typename Compare = std_cmp>
//	static	void Qsort(const RandomAccessIterator first, const int low, const int high, Compare comp = std_cmp())
//	{
//		if (low < high)
//		{
//			const int partition_indx = partition(first, low, high);
//			Qsort(first, low, partition_indx - 1, comp);
//			Qsort(first, partition_indx + 1, high, comp);
//		}
//	}