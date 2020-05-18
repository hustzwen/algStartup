#include "algStartup/sort/csrc/sort.h"

using namespace algstartup;

int main(int argc, char **argv){

	int n = 11;
	vector<dtype> nums(n, 0);
	for(int i = 0; i < n; ++i){
		nums[i] = i + 1;
	}
	//
	sort_test("bubble", bubbleSort, nums);
	sort_test("insertion", insertionSort, nums);
	sort_test("selection", selectionSort, nums);
	sort_test("merge", mergeSort, nums);
	sort_test("quick", quickSort, nums);
	system("pause");
	return 0;
}
