#include <iostream>
#include <algorithm>
#include <vector>
#include <random>
#include <ctime>
#include <list>
#include <numeric>

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
		
	for (auto i = start+1 ; i < end; i++) {
		auto tempS = i;
		auto tempP = (i - 1);
		
			while (tempP >=start &&  *tempP > *tempS) {
				if (tempP == start)
					iter_swap(tempP, tempS);
				else {
					iter_swap(tempP, tempS);
					tempS = tempS - 1;
					tempP = tempP - 1;
				}
			}
		
	}
	for (auto i = start; i < end; i++) {
		cout << *i << " ";
	}

	cout << endl;
	
	
}

template <typename RandomAccessIterator, typename LessThan>
inline void SelectSort(RandomAccessIterator start, RandomAccessIterator end, LessThan &lessThan) {
	auto pos_min = start;

	for (auto i = start; i < end-1 ; i++) {
		pos_min = i;
		for (auto j = i + 1; j < end; j++) {
			if (*j < *pos_min)
				pos_min = j;
		}
		if (*pos_min < *i) 
			iter_swap(i, pos_min);
		
		
	}
	cout << endl;
	for (auto i = start; i < end; i++) {
		cout << *i << " ";
	}

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
		for (auto c = m ; c >i+1 ;c--) {
			*c = *(c - 1);
		}
		i = min;
		//iter_swap(i, min);
		
	}

	cout << endl;
	for (auto i = start; i < end; i++) {
		cout << *i << " ";
	}

	cout << endl;
}

template <typename RandomAccessIterator, typename LessThan>
inline void HeapSort(RandomAccessIterator start, RandomAccessIterator end, LessThan &lessThan) {
	// Adicione el código de Heap Sort, use std::make_heap y std::pop_heap.
}

template <typename RandomAccessIterator, typename LessThan>
inline void Merge(RandomAccessIterator start, RandomAccessIterator end, LessThan &lessThan) {
	
}

template <typename RandomAccessIterator, typename LessThan>
inline void MergeSort(RandomAccessIterator start, RandomAccessIterator end, LessThan &lessThan) {
	auto it = start;
	int contador = 0;
	while (it<end)
	{
		contador++;
		it++;
	}
	cout << "tamaño del vector"<<contador<<endl;
}

template <typename RandomAccessIterator, typename LessThan>
inline void IterativeMergeSort(RandomAccessIterator start, RandomAccessIterator end, LessThan &lessThan) {
	// Adicione el código de Merge Sort.
}

template <typename RandomAccessIterator, typename LessThan>
inline void LomutoQuickSort(RandomAccessIterator start, RandomAccessIterator end, LessThan &lessThan) {
	// Adicione el código de Quick Sort de Lomuto.
}

template <typename RandomAccessIterator, typename LessThan>
inline void HoareQuickSort(RandomAccessIterator start, RandomAccessIterator end, LessThan &lessThan) {
	// Adicione el código de Quick Sort de Hoare.
}

template <typename RandomAccessIterator, typename LessThan>
inline void YaroslavskiyQuickSort(RandomAccessIterator start, RandomAccessIterator end, LessThan &lessThan) {
	// Adicione el código de Quick Sort con doble pivot y corte a insertion sort con pocos elementos.
}

int main(int argc, char** argv) {
	typedef void(*SORT_ALGORITHM)(std::vector<int>::iterator, std::vector<int>::iterator);
	for (//auto & i : { 100/*,1000,10'000,100'000,1'000'000,10000000,100000000 */ }) {
		auto & i :{100}){
		std::vector<int> w(i), v;
		std::iota(w.begin(), w.end(), 1);
		for (auto a = w.begin(), _a = w.begin() + i / 100; a <w.end()-1; _a += i / 100)
		{
			std::shuffle(a, _a, std::default_random_engine(std::time(0)));
			a = _a;
		}

		// retire el comentario para estudiar datos completamente desordenados:
		//std::shuffle(w.begin(), w.end(), std::default_random_engine(std::time(0)));
		
		cout << " vector ";
		for (auto i = w.begin () ; i < w.end(); i++) {
			cout << *i << " ";
		}
		cout << endl;


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
