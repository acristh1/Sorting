
#include <algorithm>
#include <vector>
#include <random>
#include <ctime>
#include <list>
#include <numeric>
#include <iostream>
#include <cmath>
#include<iterator>

#include <string>
#include <utility>

using namespace std;

template <typename T>
struct cmpLess { inline bool operator()(const T &t1, const T &t2) const { return (t1 < t2); } };

template <typename T>
struct cmpGreater { inline bool operator()(const T &t1, const T &t2) const { return (t2 < t1); } };


template <typename RandomAccessIterator>
inline void InsertSort(RandomAccessIterator start, RandomAccessIterator end) {
	cmpLess < typename RandomAccessIterator::value_type > lessThan;
	InsertSort(start, end, lessThan);
}

template <typename RandomAccessIterator>
inline void SelectSort(RandomAccessIterator start, RandomAccessIterator end) {
	cmpLess < typename RandomAccessIterator::value_type > lessThan;
	SelectSort(start, end, lessThan);
}

template <typename RandomAccessIterator>
inline void StableSelectSort(RandomAccessIterator start, RandomAccessIterator end) {
	cmpLess < typename RandomAccessIterator::value_type > lessThan;
	StableSelectSort(start, end, lessThan);
}

template <typename RandomAccessIterator>
inline void HeapSort(RandomAccessIterator start, RandomAccessIterator end) {
	cmpLess < typename RandomAccessIterator::value_type > lessThan;
	HeapSort(start, end, lessThan);
}

template <typename RandomAccessIterator>
inline void MergeSort(RandomAccessIterator start, RandomAccessIterator end) {
	cmpLess < typename RandomAccessIterator::value_type > lessThan;
	MergeSort(start, end, lessThan);
}

template <typename RandomAccessIterator>
inline void IterativeMergeSort(RandomAccessIterator start, RandomAccessIterator end) {
	cmpLess < typename RandomAccessIterator::value_type > lessThan;
	IterativeMergeSort(start, end, lessThan);
}

template <typename RandomAccessIterator>
inline void LomutoQuickSort(RandomAccessIterator start, RandomAccessIterator end) {
	cmpLess < typename RandomAccessIterator::value_type > lessThan;
	LomutoQuickSort(start, end, lessThan);
}

template <typename RandomAccessIterator>
inline void HoareQuickSort(RandomAccessIterator start, RandomAccessIterator end) {
	cmpLess < typename RandomAccessIterator::value_type > lessThan;
	HoareQuickSort(start, end, lessThan);
}

template <typename RandomAccessIterator>
inline void YaroslavskiyQuickSort(RandomAccessIterator start, RandomAccessIterator end) {
	cmpLess < typename RandomAccessIterator::value_type > lessThan;
	YaroslavskiyQuickSort(start, end, lessThan);
}


template <typename RandomAccessIterator, typename LessThan>
inline void InsertSort(RandomAccessIterator start, RandomAccessIterator end, LessThan &lessThan) {

	for (auto i = start + 1; i < end; i++) {
		auto tempS = i;
		auto tempP = (i - 1);

		while (tempP >= start &&  *tempP > *tempS) {
			if (tempP == start)
				iter_swap(tempP, tempS);
			else {
				iter_swap(tempP, tempS);
				tempS = tempS - 1;
				tempP = tempP - 1;
			}
		}

	}
	/*
	for (auto i = start; i < end; i++) {
		cout << *i << " ";
	}
*/
	cout << endl;


}

template <typename RandomAccessIterator, typename LessThan>
inline void SelectSort(RandomAccessIterator start, RandomAccessIterator end, LessThan &lessThan) {
	auto pos_min = start;

	for (auto i = start; i < end - 1; i++) {
		pos_min = i;
		for (auto j = i + 1; j < end; j++) {
			if (*j < *pos_min)
				pos_min = j;
		}
		if (*pos_min < *i)
			iter_swap(i, pos_min);


	}
	cout << endl;
	/*
	for (auto i = start; i < end; i++) {
		cout << *i << " ";
	}*/

	cout << endl;
}

template <typename RandomAccessIterator, typename LessThan>
inline void StableSelectSort(RandomAccessIterator start, RandomAccessIterator end, LessThan &lessThan) {

	for (auto i = start; i < end; i++) {
		auto  min = i;
		auto m = i;
		for (auto j = i + 1; j < end;j++) {
			if (*j < *min) {
				min = j;
				m = j;
			}
		}

		for (auto c = m; c > i + 1; c--) {
			c = (c - 1);
			//iter_swap(c,c-1);
		}
		//i = min;
		iter_swap(i, min);

	}

	cout << endl;
	/*for (auto i = start; i < end; i++) {
		cout << *i << " ";
	}
	*/
	cout << endl;
}

template <typename RandomAccessIterator, typename LessThan>
inline void HeapSort(RandomAccessIterator start, RandomAccessIterator end, LessThan &lessThan) {
	
	for (auto i = end; i > start; i--) {
		make_heap(start, i);
		pop_heap(start, i);
		//iter_swap(i, front);
	}
	cout << endl;
	/*for (auto i = start; i < end; i++) {
		cout << *i << " ";
	}
	*/
	cout << endl;
}

template <typename RandomAccessIterator, typename LessThan>
inline void Merge(RandomAccessIterator start, RandomAccessIterator end, RandomAccessIterator mid, LessThan &lessThan) {
	auto it = start;
	auto it2 = mid;

	std::vector<int> v;//vector del tipo del contenido de it.

	while (it < mid && it2 < end)
	{
		if (*it <= *it2)
		{
			v.push_back(*it);
			it++;
		}
		else
		{
			v.push_back(*it2);
			it2++;
		}
	}
	while (it < mid)
	{
		v.push_back(*it);
		it++;
	}
	if (it2 < end)
	{
		v.push_back(*it2);
		it2++;
	}
	it = start;
	for each (auto var in v)
	{
		*it = var;
		it++;
	}
	/*
	while (it2 < end)
	{
	it = it2;
	while (it != start && *it > *(it - 1))
	{
	iter_swap(it, it - 1);
	it--;
	}
	it2++;
	}
	*/

}

template <typename RandomAccessIterator, typename LessThan>
inline void MergeSort(RandomAccessIterator start, RandomAccessIterator end, LessThan &lessThan) {
	auto it = start;
	int contador = 0;
	while (it < end)
	{
		contador++;
		it++;
	}

	if (contador <= 1)
		return;

	int mid = contador / 2;
	it = start + mid;
	MergeSort(start, it);
	MergeSort(it, end);
	if (*(it - 1) <= *it)
		return;
	else
		Merge(start, end, it, lessThan);
}

template <typename RandomAccessIterator, typename LessThan>
inline std::vector<typename RandomAccessIterator::value_type> I_Merge( RandomAccessIterator start, RandomAccessIterator end, RandomAccessIterator mid,LessThan &lessThan) {
	//vector<int>v;
	std::vector<typename RandomAccessIterator::value_type> v;

	RandomAccessIterator it_l{ start }, it_r{ end };
	const RandomAccessIterator it_mid{ mid }, it_end{ end };
	while (it_l != it_mid && it_r != it_end) {
		v.push_back((*it_l <= *it_r) ? *it_l++ : *it_r++);
	}
	v.insert(v.end(), it_l, it_mid);
	v.insert(v.end(), it_r, it_end);

	

	return std::move(v);
}

template <typename RandomAccessIterator, typename LessThan>
inline void IterativeMergeSort(RandomAccessIterator start, RandomAccessIterator end, LessThan &lessThan) {
	auto it_mid = start;
	int contador = 0;
	while (it_mid < end)
	{
		contador++;
		it_mid++;
	}

	if (contador <= 1)
		return;

	int mid = contador / 2;
	it_mid = start + mid;
	
	IterativeMergeSort(start, it_mid);
	IterativeMergeSort(it_mid, end);
	std::inplace_merge(start, it_mid, end);
	/*
	auto &&v = I_Merge(start, end, it_mid, lessThan);
	
	std::move(v.cbegin(), v.cend(), start);
	*/
	
	

	;

}

template <typename RandomAccessIterator, typename LessThan>
inline RandomAccessIterator partitionL(RandomAccessIterator start, RandomAccessIterator end, LessThan &lessThan)
{
	auto pivot = *(end - 1);
	auto i = start;
	for (auto j = start; j < end - 1; j++)
	{
		if (*j <= pivot)
		{
			if (j != i)
				iter_swap(i, j);
			i++;
		}
	}
	return i;
}

template <typename RandomAccessIterator, typename LessThan>
inline void LomutoQuickSort(RandomAccessIterator start, RandomAccessIterator end, LessThan &lessThan) {
	// Adicione el cÃ³digo de Quick Sort de Lomuto.
	if (start < end - 1)
	{
		auto p = partitionL(start, end, lessThan);
		HoareQuickSort(start, p + 1);
		HoareQuickSort(p + 1, end);
	}
}

template <typename RandomAccessIterator, typename LessThan>
inline RandomAccessIterator partitionH(RandomAccessIterator start, RandomAccessIterator end, LessThan &lessThan)
{
	auto pivot = *start;
	auto i = start;
	auto j = end;
	while (true)
	{
		while (*i<pivot)
		{
			i++;
		}

		do
		{
			j--;
		} while (*j>pivot);

		if (i >= j)
		{
			return j;
		}
		iter_swap(i, j);
	}
}

template <typename RandomAccessIterator, typename LessThan>
inline void HoareQuickSort(RandomAccessIterator start, RandomAccessIterator end, LessThan &lessThan) {
	// Adicione el cÃ³digo de Quick Sort de Hoare.
	if (start < end - 1)
	{
		auto p = partitionH(start, end, lessThan);
		HoareQuickSort(start, p + 1);
		HoareQuickSort(p + 1, end);
	}
}

template <typename RandomAccessIterator, typename LessThan>
inline void YaroslavskiyQuickSort(RandomAccessIterator start, RandomAccessIterator end, LessThan &lessThan) {
	auto it = start;
	int contador = 0;
	while (it<end)
	{
		contador++;
		it++;
	}
	if (contador <= 1)
		return;
	if (contador < 8)
	{
		InsertSort(start, end);
		return;
	}

	if (*start > *(end - 1))
		iter_swap(start, (end - 1));
	auto p = *start;
	auto q = *(end - 1);

	auto l = start + 1;
	auto k = l;
	auto g = end - 2;
	while (k <= g)
	{
		if (*k < p)
		{
			iter_swap(k, l);
			l++;
		}
		else
		{
			if (*k > q)
			{
				while (*g>q && k<g)
				{
					g--;
				}
				iter_swap(k, g);
				g--;
				if (*k<p)
				{
					iter_swap(k, l);
					l++;
				}
			}
		}
		k++;
	}

	l--; g++;
	iter_swap(start, l);
	iter_swap(end - 1, g);
	YaroslavskiyQuickSort(start, l);
	YaroslavskiyQuickSort(l + 1, g);
	YaroslavskiyQuickSort(g + 1, end);
}

int main(int argc, char** argv) {
	typedef void(*SORT_ALGORITHM)(std::vector<int>::iterator, std::vector<int>::iterator);
	for (auto & i : { 100,1000,10000,100000,1000000,10000000,100000000  }) {
		//auto & i : { 100 }) {
		std::vector<int> w(i), v;
		std::iota(w.begin(), w.end(), 1);
		for (auto a = w.begin(), _a = w.begin() + i / 100; _a < w.end(); _a += i / 100)
		{
			std::shuffle(a, _a, std::default_random_engine(std::time(0)));
			a = _a;
		}

		// retire el comentario para estudiar datos completamente desordenados:
		std::shuffle(w.begin(), w.end(), std::default_random_engine(std::time(0)));
		/*IterativeMergeSort(w.begin(), w.end());
		
		for (auto i=w.begin(); i < w.end(); i++) {
			cout << *i << " ";
		}*/
		
		/*
		std::cout << " vector ";
		for (auto i = w.begin(); i < w.end(); i++) {
			std::cout << *i << " ";
		}
		std::cout << endl;
		*/

		std::vector<SORT_ALGORITHM> sort_algorithms = { InsertSort , SelectSort, StableSelectSort, HeapSort, MergeSort, IterativeMergeSort, LomutoQuickSort, HoareQuickSort };
		if (i > 100000 && i < 100000000)
		{
			sort_algorithms = { HeapSort, MergeSort, IterativeMergeSort, LomutoQuickSort, HoareQuickSort };
			std::cout << "-, -, -, ";
		}
		if (i == 100000000)
		{
			sort_algorithms = { IterativeMergeSort, LomutoQuickSort, HoareQuickSort };
			std::cout << "-, -, -, -, -, ";
		}

		for (auto & sort_algorithm : sort_algorithms) {
			v = w;
			std::clock_t inicio = std::clock();
			sort_algorithm(v.begin(), v.end());
			std::cout << 1000.0 * (double)(std::clock() - inicio) / (double)CLOCKS_PER_SEC << ", " << std::flush;
		}
		std::cout << std::endl;
	
	}
	return 0;
}
