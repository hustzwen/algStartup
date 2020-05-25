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
	/*������ת*/
	ListNode* reverse(ListNode* head);
	/*�ݹ鷭ת*/
	ListNode* reverseRecursive(ListNode* head);
	/*��תǰn���ڵ�*/
	ListNode* reverseN(ListNode* head, int n);
	/*��ת[m, n]֮��Ľڵ�*/
	ListNode* reverseBetween(ListNode* head, int m, int n);
	/*�Ƴ��ڵ�*/
	ListNode* removeElements(ListNode* head, int val);
	/*�������*/
	ListNode* cycleEntrance(ListNode* head);
	/*�ϲ�������������*/
	ListNode* mergeTwoSortedLists(ListNode* l1, ListNode* l2);
	/*�Ҹ������м�ڵ�*/
	ListNode* middleNode(ListNode* head);
	/*���鷭ת����*/
	ListNode* reversekGroup(ListNode* head, int k);
	/*������ת*/
	bool isPalindromeList(ListNode* head);
	/*����*/
	ListNode* quickSortList(ListNode* head);
	/*�鲢*/
	ListNode* mergeSortList(ListNode* head);
	/*�ϲ�k����������*/
	ListNode* mergekSortLists(std::vector<ListNode*> &lists);
}

#endif
