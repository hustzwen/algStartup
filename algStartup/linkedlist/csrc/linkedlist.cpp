#include "algStartup/linkedlist/csrc/linkedlist.h"
#include <iostream>


namespace algstartup {

void printList(ListNode* head){
	if(!head){
		std::cout << "nullptr point" << std::endl;
		return;
	}
	ListNode* phead = head;
	while (phead != nullptr)
	{
		std::cout << phead->val << " ";
		phead = phead->next;
	}
	std::cout << std::endl;
	return;
}

ListNode* reverse(ListNode* head){
	if(head == nullptr) return head;
	ListNode* cur = nullptr;
	ListNode* pre = head;
	while (pre != nullptr)
	{
		ListNode *temp = pre->next;
		pre->next = cur;
		cur = pre;
		pre = temp;
	}
	return cur;
}

ListNode* reverseRecursive(ListNode* head){
	if(head == nullptr || head->next == nullptr) return head;
	ListNode* last = reverseRecursive(head->next);
	// 类似二叉树后续遍历
	head->next->next = head;
	head->next = nullptr;
	return last;
}

/* 翻转前n个节点*/
ListNode* reverseN(ListNode* head, int n){
	if(!head || n <= 0) return nullptr;
	ListNode* next = nullptr;
	if(1 == n){
		return head;
	}
	ListNode* last = reverseN(head->next, n - 1);
	next = head->next->next; // 
	head->next->next = head; //
	head->next = next;
	return last;

}
/*翻转从[m, n]的节点 */
ListNode* reverseBetween(ListNode* head, int m, int n){
	if(!head || m > n || m <= 0) return nullptr;
	if(1 == m){
		return reverseN(head, n);
	}
	//
	head->next = reverseBetween(head->next, m-1, n-1);
	return head;
}

ListNode* removeElements(ListNode* head, int val){
	ListNode* dummy = new ListNode(-1);
	// 添加哨兵
	dummy->next = head;
	head = dummy;

	while (head->next!= nullptr)
	{
		if(val == head->next->val){
			head->next = head->next->next;
		}else{
			head = head->next;
		}
	}

	return dummy->next;
}

ListNode* mergeTwoSortedLists(ListNode* l1, ListNode* l2){
	// 哨兵
	ListNode *dummy = new ListNode(-1);
	ListNode *cur = dummy;

	while (l1 != nullptr && l2 != nullptr)
	{
		if(l1->val < l2->val){
			cur->next = l1;
			cur = cur->next;
			l1 = l1->next;
		}else
		{
			cur->next = l2;
			cur = cur->next;
			l2 = l2->next;
		}
	}

	cur->next = (l1 == nullptr )?l2:l1;

	return dummy->next;

}

ListNode* middleNode(ListNode* head){
	if(!head || !head->next) return head;
	ListNode *slow = head, *fast = head;
	while (fast != nullptr && fast->next != nullptr)
	{
		slow = slow->next;
		fast= fast->next->next;
	}
	return slow;
}

/* 翻转[node1, node2)之间的节点*/
ListNode* reverse(ListNode* node1, ListNode* node2){
	ListNode* cur = nullptr, *pre = node1;
	while (pre != node2) // stop condition, pre == node2
	{
		ListNode* temp = pre->next;
		pre->next = cur;
		cur = pre;
		pre = temp;
	}
	return cur;
}

ListNode* reversekGroup(ListNode* head, int k){
	if (head == nullptr || k <= 0) return nullptr;
	ListNode *node1 = head, *node2 = head;
	// [node1, node2)
	for(int i = 0; i < k; ++i){
		if(node2 == nullptr) return head;
		node2 = node2->next;
	}
	ListNode * new_head = reverse(node1, node2);
	node1->next = reversekGroup(node2, k);
	return new_head;
}

bool isPalindromeList(ListNode* head){
	if(!head) return true;
	ListNode *slow = head, *fast = head;
	while (fast != nullptr && fast->next != nullptr)
	{
		slow = slow->next;
		fast = fast->next->next;
	}
	// 奇数
	if(fast != nullptr) slow = slow->next;
	//
	ListNode *right = reverse(slow);
	ListNode* left = head;

	while (right != nullptr)
	{
		if(left->val != right->val) return false;
		left = left->next;
		right = right->next;
	}
	return true;
}


ListNode* quickSortList(ListNode* head){
	// stop condition
	if(head == nullptr || head->next == nullptr) return head;
	int pivot = head->val;
	// 哨兵
	ListNode* cur = head;
	ListNode* ls = new ListNode(-1);
	ListNode* rs = new ListNode(-1);
	ListNode *l = ls;
	ListNode *r = rs;
	// 分区
	while (cur != nullptr) // cur == nullptr
	{
		if (cur->val < pivot)
		{
			l->next = cur;
			l = l->next;
		}else
		{
			r->next = cur;
			r = r->next;
		}
		cur = cur->next;
	}
	//拼接
	l->next = rs->next;
	r->next = nullptr;

	// head 在rs->next
	ListNode *right = quickSortList(head->next);
	head->next = nullptr;
	ListNode *left = quickSortList(ls->next);
	// 拼接
	cur = left;
	while (cur->next != nullptr) // cur->next = nullptr
	{
		cur = cur->next;
	}
	cur->next = right;

	delete ls, rs;
	ls = nullptr, rs = nullptr;

	return left;
}

}