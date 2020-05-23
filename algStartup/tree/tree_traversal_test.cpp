#include "algStartup/tree/csrc/tree_traversal.h"
#include <iostream>

using namespace algstartup;

int main(int argc, char** argv){
	
	TreeNode *A = new TreeNode(1);
	TreeNode *B = new TreeNode(2);
	TreeNode *C = new TreeNode(3);
	TreeNode *D = new TreeNode(4);
	TreeNode *E = new TreeNode(5);
	TreeNode *F = new TreeNode(6);
	TreeNode *G = new TreeNode(7);

	TreeNode *root = A;
	root->left = B;
	root->left->left = C;
	root->left->right = E;
	root->left->left->right = D;
	//
	root->right = F;
	root->right->left = G;
	
	preorder_travasel(root);
	std::cout << std::endl;
	inorder_travasel(root);
	std::cout << std::endl;
	postorder_travasel(root);
	std::cout << std::endl;
	vector<vector<int>>  res = level_travasel(root);

	delete A, B, C, D, E, F, G;
	A = nullptr, B = nullptr, C = nullptr, D = nullptr;
	E =nullptr, F = nullptr, G = nullptr;

	system("pause");
	return 0;
}