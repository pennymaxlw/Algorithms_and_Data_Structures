#include <algorithm>
#include <iterator>
#include <vector>
#include <iostream>
using namespace std;

template<class ForwardIterator>
void merge_aux(ForwardIterator first, ForwardIterator mid, ForwardIterator last) {
	typedef typename iterator_traits<ForwardIterator>::value_type value_type;
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

template<class ForwardIterator>
void merge_sort(ForwardIterator first, ForwardIterator last) {
	if (first == last) return;
	typedef typename iterator_traits<ForwardIterator>::difference_type diff_type;
	diff_type diff = distance(first, last);
	ForwardIterator mid = first;
	if (diff > 1) {
		advance(mid, diff/2);
		merge_sort(first, mid);
		merge_sort(mid, last);
		merge_aux(first, mid, last);
	}
}

template<class RandomAccessIterator>
void insertion_sort(RandomAccessIterator first, RandomAccessIterator last) {
	if (first == last) return;
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
	if (first == last) return;
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
	if (first == last) return;
	RandomAccessIterator iter1, iter2;
	for (iter1 = first; iter1 != last - 1; ++iter1) {
		for (iter2 = last - 1; iter2 != first; --iter2) {
			if (*iter2 < *(iter2 - 1))	iter_swap(iter2, iter2 - 1);
		}
	}
}

void test_sorting_template();
