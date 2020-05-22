#include "algStartup/search/csrc/search.h"
#include <queue>

namespace algstartup{

int binary_search(vector<dtype> &nums, dtype target){

	if(nums.empty()) return -1;
	int left = 0, right = nums.size() - 1;
	int mid = 0;

	while (left <= right)
	{
		mid = left + (right - left) / 2;
		if(nums[mid] == target){
			return mid;
		}else if (nums[mid] > target)
		{
			right = mid - 1;
		}else if(nums[mid] < target)
		{
			 left = mid + 1;
		}
	}
	
	return -1;
}

int left_bound(vector<dtype> &nums, dtype target){

	if(nums.empty()) return -1;
	int left = 0, right = nums.size() - 1;
	int mid = 0;

	while (left <= right)
	{
		mid = left + (right - left) / 2;
		if(nums[mid] == target){
			right = mid - 1;
		}else if (nums[mid] > target)
		{
			right = mid - 1;
		}else if(nums[mid] < target)
		{
			left = mid + 1;
		}
	}
	// check index range 
	if(left >= nums.size() || nums[left] != target) return -1;

	return left;
}

int right_bound(vector<dtype> &nums, dtype target){

	if(nums.empty()) return -1;
	int left = 0, right = nums.size() - 1;
	int mid = 0;

	while (left <= right)
	{
		mid = left + (right - left) / 2;
		if(nums[mid] == target){
			left = mid + 1;
		}else if (nums[mid] > target)
		{
			right = mid - 1;
		}else if(nums[mid] < target)
		{
			left = mid + 1;
		}
	}
	// check index range 
	if(right < 0 || nums[right] != target) return -1;
	return right;
}

int left_bound_another(vector<dtype> &nums, dtype target){
	// consider search range, [left, right)
	if(nums.empty()) return -1;
	int left = 0, right = nums.size();
	int mid = 0;

	while (left < right)
	{
		mid = left + (right - left) / 2;
		if(nums[mid] == target){
			right = mid;
		}else if (nums[mid] > target)
		{
			right = mid;
		}else if(nums[mid] < target)
		{
			left = mid + 1;
		}
	}
	// check index range 
	if(nums[left] != target) return -1;

	return left;
}

int right_bound_another(vector<dtype> &nums, dtype target){
	// consider search range, [left, right)
	if(nums.empty()) return -1;
	int left = 0, right = nums.size();
	int mid = 0;

	while (left < right)
	{
		mid = left + (right - left) / 2;
		if(nums[mid] == target){
			left = mid + 1;
		}else if (nums[mid] > target)
		{
			right = mid;
		}else if(nums[mid] < target)
		{
			left = mid + 1;
		}
	}
	// check index range, left - 1
	if(right == 0) return -1;
	if(nums[right - 1] != target) return -1;
	return right -1;
}

Region connectedComponents(vector<vector<int>>& matrix, int target){
	Region regions;
	int n = matrix.size();
	int label = 0;
	if(0 == n) return regions;
	int m = matrix[0].size();
	int offsets[5] = {0, 1, 0, -1, 0};
	//
	std::queue<Point> q;
	for (int i =0; i < n; ++i)
	{
		for (int j=0; j<m; ++j)
		{
			if(matrix[i][j] == target){
				q.push(Point(i, j));
				vector<Point> region;
				while (!q.empty())
				{
					Point last = q.front();
					q.pop();
					matrix[i][j] = 0;
					region.push_back(last);
					int ti = last.first, tj = last.second;
					for(int k = 0; k < 4; ++k){
						ti += offsets[k];
						tj += offsets[k+1];
						if(ti >= 0 && ti < n && tj >=0 && tj < m && matrix[ti][tj] == target){
							q.push(Point(ti, tj));
							matrix[ti][tj] = 0;
						}
					}// loop k
				}
				regions[label++] = region;
			}// end if
		}// loop j
	}// loop i
	return regions;
}

void dfs(vector<vector<int>>& matrix, int i, int j, int target, vector<Point>& region){
	int n = matrix.size();
	int m = matrix[0].size();
	// stop condition
	if(i < 0 || j < 0|| i == n || j == m || matrix[i][j] == 0){
		return;
	}

	dfs(matrix, i + 1, j, target, region);
	dfs(matrix, i - 1, j, target, region);
	dfs(matrix, i, j + 1, target, region);
	dfs(matrix, i, j - 1, target, region);
	return;
}

Region connectedComponents_v1(vector<vector<int>>& matrix, int target){
	Region regions;
	int n = matrix.size();
	int label = 0;
	if(0 == n) return regions;
	int m = matrix[0].size();
	//
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			vector<Point> region;
			if (target == matrix[i][j])
			{
				region.push_back(Point(i, j));
				matrix[i][j] = 0;
				dfs(matrix, i, j, target, region);
			}
			regions[label++] = region;
		}
	}
	return regions;
}

}