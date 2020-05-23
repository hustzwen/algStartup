#include "algStartup/tree/csrc/tree_traversal.h"
#include <iostream>
#include <stack>
#include <queue>

namespace algstartup{

void preorder_travasel(TreeNode *root){
	if(!root){
		std::cout << "nullptr point" << std::endl;
		return;
	}
	std::stack<TreeNode*> stack;
	TreeNode *p = root;
	while (p || !stack.empty())
	{
		while (p != nullptr)
		{
			std::cout << p->val << " ";
			stack.push(p);
			p = p->left;
		}
		//
		p = stack.top();
		stack.pop();
		p = p->right;
	}
	return;
}

void inorder_travasel(TreeNode *root){
	if(!root){
		std::cout << "nullptr point" << std::endl;
		return;
	}
	std::stack<TreeNode*> stack;
	TreeNode *p = root;
	while (p || !stack.empty())
	{
		while (p != nullptr)
		{
			stack.push(p);
			p = p->left;
		}
		//
		p = stack.top();
		stack.pop();
		std::cout << p->val << " ";
		p = p->right;
	}
	return;
}

void postorder_travasel(TreeNode *root){

	if(!root){
		std::cout << "nullptr point" << std::endl;
		return;
	}
	std::stack<TreeNode*> stack;
	TreeNode *p = root;
	TreeNode *last = nullptr;
	while (p || !stack.empty()){
		if (p != nullptr)
		{
			while (p != nullptr)
			{
				stack.push(p);
				p = p->left;
			}	
		}else{
			p = stack.top();
			if(p->right != nullptr && p->right != last){
				p = p->right;
				stack.push(p);
				p = p->left;
			}else{
				stack.pop();
				std::cout << p->val << " ";
				last = p;
				p = nullptr;
			}
		}
	}
	return;
}

vector<vector<int>> level_travasel(TreeNode *root){
	vector<vector<int>> res;
	if(!root){
		std::cout << "nullptr point" << std::endl;
		return res;
	}
	TreeNode *cur = nullptr;
	std::queue<TreeNode*> q;
	int level = 1;
	q.push(root);
	while (!q.empty())
	{
		int size = q.size();
		if(size > 0){
			std::cout << "level " << level << " : ";
		}
		vector<int> vecs;
		for (int k = 0; k < size; ++k)
		{
			cur = q.front();
			q.pop();
			std::cout << cur->val << " ";
			vecs.push_back(cur->val);
			//
			if (cur->left != nullptr)
			{
				q.push(cur->left);
			}
			if(cur->right != nullptr)
			{
				q.push(cur->right);
			}
		}
		std::cout << std::endl;
		++level;
		res.push_back(vecs);
	}

	return res;
}

}