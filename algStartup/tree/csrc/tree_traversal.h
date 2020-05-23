#ifndef TREE_TRAVERSAL_H_
#define TREE_TRAVERSAL_H_

#include <vector>

namespace algstartup{

using std::vector;
using std::string;

struct TreeNode{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x):val(x), left(nullptr), right(nullptr) {}
};

void preorder_travasel(TreeNode *root);
void inorder_travasel(TreeNode *root);
void postorder_travasel(TreeNode *root);
vector<vector<int>> level_travasel(TreeNode *root);

}


#endif