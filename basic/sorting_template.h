#include <algorithm>
#include <iterator>
#include <vector>
#include <map>
#include <string>
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

template<typename BidirectionalIterator>
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

template<typename BidirectionalIterator>
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

template<typename RandomAccessIterator>
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

template<typename RandomAccessIterator>
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

template<typename RandomAccessIterator>
void bubble_sort(RandomAccessIterator first, RandomAccessIterator last) {
	if (first == last || distance(first, last) == 1) return;
	RandomAccessIterator iter1, iter2;
	for (iter1 = first; iter1 != last - 1; ++iter1) {
		for (iter2 = last - 1; iter2 != first; --iter2) {
			if (*iter2 < *(iter2 - 1))	iter_swap(iter2, iter2 - 1);
		}
	}
}

template<typename RandomAccessIterator>
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

template<typename RandomAccessIterator>
void quick_sort(RandomAccessIterator first, RandomAccessIterator last) {
	if (first == last || distance(first, last) == 1) return;
	srand(time(NULL));
	if (distance(first, last) > 1) {
		RandomAccessIterator pos = quick_sort_partition(first, last);
		quick_sort(first, pos);
		quick_sort(pos + 1, last);	
	}
}

template<typename RandomAccessIterator>
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

template<typename RandomAccessIterator, typename Radix>
void radix_count(RandomAccessIterator first, RandomAccessIterator last, size_t max_iteration, Radix) {
	if (first == last || distance(first, last) == 1) return;
	for (size_t i = 0; i < max_iteration; ++i) {
		Radix radix(i);
		stable_sort(first, last, radix);
		//cout << "+++++++++++" << endl;
		//copy(first, last, ostream_iterator<string>(cout, "\n"));
	}	
}

struct RadixInt {
	int radix_;
	RadixInt(int i = 0) {
		radix_ = 1;
		while (i-- >= 0) radix_ *= 10;	
	}
	bool operator()(int i, int j) {
		return (i % radix_) < (j % radix_);
	}
};

struct RadixString {
	int offset_;
	RadixString(int i = 0) : offset_(i) {}
	bool operator()(string a, string b) {
		return a[offset_] < b[offset_];	
	}
};

template<typename RandomAccessIterator, typename Hash>
//template<typename RandomAccessIterator, typename Hash, typename Key>
void bucket_sort(RandomAccessIterator first, RandomAccessIterator last, Hash h) {
	if (first == last || distance(first, last) == 1) return;
	typedef typename iterator_traits<RandomAccessIterator>::value_type value_type;
	map<value_type, vector<value_type> > bucket;
	RandomAccessIterator it = first;
	for (; it != last; ++it) {	
		value_type key = h(*it);
		if (bucket.count(key)) {
			bucket[key].push_back(*it);
		} else {
			bucket[key] = vector<value_type>(1, *it);
		}
	}
	typename map<value_type, vector<value_type> >::iterator it2 = bucket.begin();
	typename vector<value_type>::iterator it3;
	for (; it2 != bucket.end(); ++it2) {
		insertion_sort((*it2).second.begin(), (*it2).second.end());
		//(*it2).second.sort();
		for (it3 = (*it2).second.begin(); it3 != (*it2).second.end(); ++it3) {
			*first++ = *it3;
		}
	}
}

template<typename T, typename Comp = greater<T>, typename Sequence = vector<T> >
class Heap {
public:
	template<typename InputIterator>
	Heap(InputIterator first, InputIterator last) 
		: v_(first, last), size_(distance(first, last)) {
		build();
		//print();
	}
	Heap() : size_(0) {}
	void push(T t) {}
	void pop() {}
	template<typename OutputIterator>
	void sort(OutputIterator result) {
		Heap h(*this);	
		for (int i = h.size_ - 1; i > 0; i--) {
			swap(h.v_[0], h.v_[i]);
			--h.size_;
			h.heapify(0);
		}
		copy(h.v_.begin(), h.v_.end(), result);
	}
	size_t size() {return size_;}
	void print() {
		cout << "Heap members: "; 
		copy(v_.begin(), v_.end(), ostream_iterator<T>(cout, " "));
		cout << endl;
	}
private:
	void build() {
		if (size_ < 2) return;
		for (int i = size_ / 2; i >= 0; --i) {
			heapify(i);	
		}
	}
	void heapify(size_t i) {
		if (size_ < 2) return;
		size_t l = 2 * i + 1;
		size_t r = l + 1;
		size_t max = 0;
		if (l < size_ && Comp()(v_[l], v_[i]))
			max = l;
		else
			max = i;
		if (r < size_ && Comp()(v_[r], v_[max]))
			max = r;
		if (max != i) {
			swap(v_[i], v_[max]);
			heapify(max);
		}
	}	
private:
	Sequence v_;
	size_t size_;
};

template<typename RandomAccessIterator>
void heap_sort(RandomAccessIterator first, RandomAccessIterator last) {
	typedef typename iterator_traits<RandomAccessIterator>::value_type T;
	Heap<T> h(first, last);	
	h.sort(first);
}

void test_sorting_template();
