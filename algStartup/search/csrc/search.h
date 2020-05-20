#ifndef SEARCH_H_
#define SEARCH_H_

#include <vector>

namespace algstartup{

	using std::vector;
	using std::string;

	typedef int dtype;

	int binary_search(vector<dtype> &nums, dtype target);
	int left_bound(vector<dtype> &nums, dtype target);
	int right_bound(vector<dtype> &nums, dtype target);

	int left_bound_another(vector<dtype> &nums, dtype target);
	int right_bound_another(vector<dtype> &nums, dtype target);

}


#endif