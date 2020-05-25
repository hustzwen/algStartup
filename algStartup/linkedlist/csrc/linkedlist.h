#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_

#include <vector>

namespace algstartup{

	struct ListNode
	{
		int val;
		ListNode *next;
		ListNode(int x):val(x), next(nullptr){}
	};

	void printList(ListNode* head);
	/*迭代翻转*/
	ListNode* reverse(ListNode* head);
	/*递归翻转*/
	ListNode* reverseRecursive(ListNode* head);
	/*翻转前n个节点*/
	ListNode* reverseN(ListNode* head, int n);
	/*翻转[m, n]之间的节点*/
	ListNode* reverseBetween(ListNode* head, int m, int n);
	/*移除节点*/
	ListNode* removeElements(ListNode* head, int val);
	/*链表环入口*/
	ListNode* cycleEntrance(ListNode* head);
	/*合并两个有序链表*/
	ListNode* mergeTwoSortedLists(ListNode* l1, ListNode* l2);
	/*找个链表中间节点*/
	ListNode* middleNode(ListNode* head);
	/*分组翻转链表*/
	ListNode* reversekGroup(ListNode* head, int k);
	/*迭代翻转*/
	bool isPalindromeList(ListNode* head);
	/*快排*/
	ListNode* quickSortList(ListNode* head);
	/*归并*/
	ListNode* mergeSortList(ListNode* head);
	/*合并k个排序链表*/
	ListNode* mergekSortLists(std::vector<ListNode*> &lists);
}

#endif
