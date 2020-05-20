#include "algStartup/search/csrc/search.h"

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

}