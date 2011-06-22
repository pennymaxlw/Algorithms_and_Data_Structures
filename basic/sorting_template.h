#include <algorithm>
#include <iterator>
#include <vector>
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

template<class BidirectionalIterator>
void merge_aux(BidirectionalIterator first, BidirectionalIterator mid, BidirectionalIterator last) {
	typedef typename iterator_traits<BidirectionalIterator>::value_type value_type;
	vector<value_type> left, right;
	copy(first, mid, back_inserter(left));
	copy(mid, last, back_inserter(right));
	
	//merge(left.begin(), left.end(), right.begin(), right.end(), first);
	typename vector<value_type>::iterator iter_left, iter_right;
	iter_left = left.begin();
	iter_right = right.begin();
	while (iter_left != left.end() && iter_right != right.end()) {
		if (*iter_left < *iter_right) {
			*first = *iter_left++;
		} else {
			*first = *iter_right++;
		}
		++first;
	}
	copy(iter_left, left.end(), first);
	copy(iter_right, right.end(), first);
}

template<class BidirectionalIterator>
void merge_sort(BidirectionalIterator first, BidirectionalIterator last) {
	if (first == last || distance(first, last) == 1) return;
	typedef typename iterator_traits<BidirectionalIterator>::difference_type diff_type;
	diff_type diff = distance(first, last);
	BidirectionalIterator mid = first;
	if (diff > 1) {
		advance(mid, diff/2);
		merge_sort(first, mid);
		merge_sort(mid, last);
		merge_aux(first, mid, last);
	}
}

template<class RandomAccessIterator>
void insertion_sort(RandomAccessIterator first, RandomAccessIterator last) {
	if (first == last || distance(first, last) == 1) return;
	RandomAccessIterator iter1 = first + 1;
	RandomAccessIterator iter2;
	for (; iter1 != last; ++iter1) {
		typename iterator_traits<RandomAccessIterator>::value_type key = *iter1;
		iter2 = iter1 - 1;
		while (iter2 != first - 1 && *iter2 > key) {
			*(iter2 + 1) = *iter2;
			--iter2;
		}
		*++iter2 = key;
	}
}

template<class RandomAccessIterator>
void selection_sort(RandomAccessIterator first, RandomAccessIterator last) {
	if (first == last || distance(first, last) == 1) return;
	RandomAccessIterator iter1, iter2, iter_smallest;
	for (iter1 = first; iter1 != last - 1; ++iter1) {
		iter_smallest = iter1;
		for (iter2 = iter1 + 1; iter2 != last; ++iter2) {
			if (*iter2 < *iter_smallest) iter_smallest = iter2;
		}
		iter_swap(iter1, iter_smallest);
	}
}

template<class RandomAccessIterator>
void bubble_sort(RandomAccessIterator first, RandomAccessIterator last) {
	if (first == last || distance(first, last) == 1) return;
	RandomAccessIterator iter1, iter2;
	for (iter1 = first; iter1 != last - 1; ++iter1) {
		for (iter2 = last - 1; iter2 != first; --iter2) {
			if (*iter2 < *(iter2 - 1))	iter_swap(iter2, iter2 - 1);
		}
	}
}

template<class RandomAccessIterator>
RandomAccessIterator quick_sort_partition(RandomAccessIterator first, RandomAccessIterator last) {
	int offset = rand() % distance(first, last);
	RandomAccessIterator pos = first + offset;
	iter_swap(pos, last - 1);
	RandomAccessIterator store = first;
	pos = first;
	for (; pos != last - 1; ++pos) {
		if (*pos < *(last - 1)) iter_swap(store++, pos);
	}	
	iter_swap(store, last - 1);
	return store;
}

template<class RandomAccessIterator>
void quick_sort(RandomAccessIterator first, RandomAccessIterator last) {
	if (first == last || distance(first, last) == 1) return;
	srand(time(NULL));
	if (distance(first, last) > 1) {
		RandomAccessIterator pos = quick_sort_partition(first, last);
		quick_sort(first, pos);
		quick_sort(pos + 1, last);	
	}
}

template<class RandomAccessIterator>
void counting_sort(RandomAccessIterator first, RandomAccessIterator last) {
	if (first == last || distance(first, last) == 1) return;
	typedef typename iterator_traits<RandomAccessIterator>::value_type value_type;
	value_type max = *max_element(first, last);
	value_type min = *min_element(first, last);
	size_t size = max - min + 1;
	vector<value_type> basic(size, 0);
	RandomAccessIterator it = first;
	for (; it != last; ++it) {
		++basic[*it - min];
	}
	for (size_t idx = 0; idx < size; ++idx) {
		while (basic[idx] > 0) {
			*first++ = idx + min;
			--basic[idx];
		}	
	}
}

void test_sorting_template();
