#include "algStartup/backtrack/csrc/solve_n_queens.h"

namespace algstartup{

vector<vector<string>> solve_n_queens(int n){

	vector<vector<string>> res;
	if(n <= 0) return res;
	vector<string> board(n, string(n, '.'));
	backTrack(board, 0, res);
	return res;
}

bool isValid(vector<string>& board, int row, int col){
	int n  = board.size();
	// check column
	for (int i = 0; i < row; ++i)
	{
		if(board[i][col] == 'Q'){
			return false;
		}
	}
	// top-right
	for (int i = row -1, j = col + 1; i >= 0&& j < n; --i, ++j)
	{
		if(board[i][j] == 'Q'){
			return false;
		}
	}
	// top-left
	for (int i = row - 1, j = col - 1; i >= 0&& j >= 0; --i, --j)
	{
		if(board[i][j] == 'Q'){
			return false;
		}
	}	
	return true;
}

void backTrack(vector<string>& board, int row, vector<vector<string>>& res){
	// stop condition
	if(row == board.size()){
		res.push_back(board);
		return;
	}
	int n = board[row].size();
	for (int col = 0; col < n; ++col)
	{
		if(!isValid(board, row, col)){
			continue;
		}
		// do choice
		board[row][col] = 'Q';
		backTrack(board, row+1, res);
		// undo choice
		board[row][col] = '.';
	}
}



}