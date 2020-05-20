#include "algStartup/sort/csrc/sort.h"
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <iomanip>
#include <algorithm>

namespace algstartup{

	void bubbleSort(vector<dtype> &nums, int n){
		if(nums.empty() || n <= 1) return;
		for (int i = 0; i < n; i++)
		{
			bool flag = true; // 
			for (int j = 0; j < n - 1- i; j++)
			{
				if(nums[j] > nums[j+1]){
					std::swap(nums[j], nums[j+1]);
					flag = false;
				}
			}
			if(flag) break;
		}
		return;
	}

	void insertionSort(vector<dtype> &nums, int n){
		if(nums.empty() || n <= 1) return;
		for(int i = 1; i < n; ++i){
			dtype value = nums[i];
			int j = i - 1;
			for(; j >= 0; --j){
				if(nums[j] > value){
					nums[j+1] = nums[j];
				}else{
					break;
				}
			}
			nums[j+1] = value;
		}
		return;
	}

	void selectionSort(vector<dtype> &nums, int n){
		if(nums.empty() || n <= 1) return;
		for(int i = 0; i < n; ++i){
			int index = i;
			for(int j = i + 1; j < n; ++j){
				if(nums[j] < nums[i]){
					index = j;
				}
			}
			std::swap(nums[i], nums[index]);
		}
	}

	// merge sort
	static void merge(vector<dtype> &nums, int lo, int mid, int hi){
		int i = lo, j = mid + 1;
		vector<dtype> aux(nums.size());
		for(int k = lo; k <= hi; ++k){
			aux[k] = nums[k];
		}
		for(int k = lo; k <= hi; k++){
			if(i > mid) nums[k] = aux[j++];
			else if(j > hi) nums[k] = aux[i++];
			else if(aux[i] > aux[j]) nums[k] = aux[j++];
			else nums[k] = aux[i++];
		}
	}

	static void mergeSortRecursive(vector<dtype> &nums, int lo, int hi){
		if(lo >= hi) return;
		int mid = lo + (hi - lo) / 2;
		mergeSortRecursive(nums, lo, mid);
		mergeSortRecursive(nums, mid+1, hi);
		merge(nums, lo, mid, hi);
	}

	void mergeSort(vector<dtype> &nums, int n){
		if(nums.empty() || n <= 1) return;
		mergeSortRecursive(nums, 0, n-1);
	}

	// quick sort
	static int partition(vector<dtype> &nums, int lo, int hi){
		dtype pivot = nums[hi];
		int i = lo;
		for(int j = lo; j < hi; j++){ // j := lo ... hi-1
			if(nums[j] < pivot){
				std::swap(nums[i], nums[j]);
				i += 1;
			}
		}
		std::swap(nums[hi], nums[i]);
		return i;
	}

	static void quickSortRecursive(vector<dtype> &nums, int lo, int hi){
		if(lo >= hi) return;
		int q = partition(nums, lo, hi);
		quickSortRecursive(nums, lo, q-1);
		quickSortRecursive(nums, q+1, hi);
	}

	void quickSort(vector<dtype> &nums, int n){
		if(nums.empty() || n <= 1) return;
		quickSortRecursive(nums, 0, n-1);
	}

	void print_vector(dtype *data_ptr, int len){
		const int max_out = 10;
		if(len == 0) return;

		std::cout << "[";
		if(len <= max_out){ // short str
			for (int i = 0; i < len; ++i){
				std::cout << std::setw(5) << std::right << data_ptr[i];
				if(i != len	- 1) std::cout << ",";
			}
		}else{ // long str
			for (int i = 0; i < max_out/2; i++){
				std::cout << std::setw(5) << std::right << data_ptr[i];
				std::cout << ",";
			}
			std::cout << "   ...";
			for (int i = max_out/2-1; i >=0; --i){
				std::cout << std::setw(5) << std::right << data_ptr[len-1-i];
				if(len != 0) std::cout << ",";
			}
		}
		std::cout << "]" << std::endl;
	}

	void sort_test(const char *type, pf func, vector<dtype> &nums){
		// shuffle
		std::cout << type << " sort: " << std::endl;
		std::random_shuffle(nums.begin(), nums.end());
		print_vector(nums.data(), nums.size());
		func(nums, nums.size());
		print_vector(nums.data(), nums.size());
		std::random_shuffle(nums.begin(), nums.end());
		return;
	}

}