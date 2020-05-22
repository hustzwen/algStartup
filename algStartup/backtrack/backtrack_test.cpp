#include "algStartup/backtrack/csrc/solve_n_queens.h"
#include <iostream>

using namespace algstartup;

int main(int argc, char **argv){

	/* N queens testing */
	vector<vector<string>> res;
	int n = 8;
	res = solve_n_queens(n);
	std::cout << n << " queens has " << res.size() << " solutions" << std::endl;
	for(int k = 0; k < res.size(); ++k){
		std::cout << "solution: " << k+1 << ": " << std::endl;
		for (int i = 0; i < n; ++i)
		{
			std::cout << (res[k][i]).c_str() << std::endl;
		}
	}

	system("pause");
	return 0;
}