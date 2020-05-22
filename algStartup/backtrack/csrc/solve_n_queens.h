#ifndef SOLVE_N_QUEENS_H_
#define SOLVE_N_QUEENS_H_

#include <vector>

namespace algstartup {

using std::string;
using std::vector;

vector<vector<string>> solve_n_queens(int n);

void backTrack(vector<string>& board, int row, vector<vector<string>>& res);

}

#endif
