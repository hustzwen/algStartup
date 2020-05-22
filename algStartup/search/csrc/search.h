#ifndef SEARCH_H_
#define SEARCH_H_

#include <vector>
#include <utility>
#include <unordered_map>

namespace algstartup{

	using std::vector;
	using std::string;

	typedef int dtype;
	typedef std::pair<int, int> Point;
	typedef std::unordered_map<int, vector<Point>> Region;

	int binary_search(vector<dtype> &nums, dtype target);
	int left_bound(vector<dtype> &nums, dtype target);
	int right_bound(vector<dtype> &nums, dtype target);

	int left_bound_another(vector<dtype> &nums, dtype target);
	int right_bound_another(vector<dtype> &nums, dtype target);

	Region connectedComponents(vector<vector<int>>&, int);
	Region connectedComponents_v1(vector<vector<int>>&, int);
}

#endif