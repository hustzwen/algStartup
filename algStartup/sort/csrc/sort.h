#ifndef SORT_H_
#define SORT_H_

#include <vector>

namespace algstartup{

	using std::vector;
	using std::string;

	typedef float dtype;
	typedef void (*pf)(vector<dtype>&, int);

	void bubbleSort(vector<dtype> &nums, int n);
	void insertionSort(vector<dtype> &nums, int n);
	void selectionSort(vector<dtype> &nums, int n);
	void mergeSort(vector<dtype> &nums, int n);
	void quickSort(vector<dtype> &nums, int n);

	void sort_test(const char *type, pf func, vector<dtype> &nums);
}


#endif
