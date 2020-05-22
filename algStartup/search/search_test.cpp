#include "algStartup/search/csrc/search.h"
#include <iostream>

using namespace algstartup;

void print_matrix(vector<vector<int>>& matrix, int m, int n){
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			std::cout << matrix[i][j] << "  ";
		}
		std::cout << std::endl;
	}
}

int main(int argc, char **argv){
	/*test binary search */
	int n = 99;
	vector<dtype> nums(n, 0);
	for(int i = 0; i < n; ++i){
		nums[i] = static_cast<dtype>(i + 1);
	}
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

	/* test BFS and DFS*/
	const int mm = 10, nn = 10;
	vector<vector<int>> matrix(mm, vector<int>(nn, 0));
	for (int i = 2; i < mm; ++i)
	{
		for (int j = 3; j < nn; ++j){
			matrix[i][j] = 1;
		}
		if (i == 5) i += 2;
	}
	// print matrix
	print_matrix(matrix, mm, nn);
	// bfs
	Region region = connectedComponents(matrix, 1);
	for (int k = 0; k < region.size(); k++)
	{
		vector<Point> Points = region[k];
		for (int l = 0; l < Points.size(); ++l)
		{
			Point point = Points[l];
			matrix[point.first][point.second] = 9;
		}
	}
	std::cout << std::endl;
	print_matrix(matrix, mm, nn);
	// dfs
	region = connectedComponents_v1(matrix, 9);
	for (int k = 0; k < region.size(); k++)
	{
		vector<Point> Points = region[k];
		for (int l = 0; l < Points.size(); ++l)
		{
			Point point = Points[l];
			matrix[point.first][point.second] = 99;
		}
	}
	std::cout << std::endl;
	print_matrix(matrix, mm, nn);

	system("pause");
	return 0;
}
