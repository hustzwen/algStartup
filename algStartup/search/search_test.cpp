#include "algStartup/search/csrc/search.h"
#include <iostream>

using namespace algstartup;

int main(int argc, char **argv){

	int n = 99;
	vector<dtype> nums(n, 0);
	for(int i = 0; i < n; ++i){
		nums[i] = static_cast<dtype>(i + 1);
	}
	//
	dtype target = 98;
	int index;
	index = binary_search(nums, target);
	std::cout << "target: " << target << ", index: " << index << std::endl;
	//
	dtype arr[6] = {1, 2, 3, 6, 6, 6};
	vector<dtype> dnums(arr, arr+6);
	target = 6;
	index = left_bound(dnums, target);
	std::cout << "target: " << target << ", index: " << index << std::endl;
	index = left_bound_another(dnums, target);
	std::cout << "target: " << target << ", index: " << index << std::endl;
	index = right_bound(dnums, target);
	std::cout << "target: " << target << ", index: " << index << std::endl;
	index = right_bound_another(dnums, target);
	std::cout << "target: " << target << ", index: " << index << std::endl;
	system("pause");
	return 0;
}
