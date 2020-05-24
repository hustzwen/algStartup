#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_

namespace algstartup{

	struct ListNode
	{
		int val;
		ListNode *next;
		ListNode(int x):val(x), next(nullptr){}
	};

	void printList(ListNode* head);
	ListNode* reverse(ListNode* head);
	ListNode* reverseRecursive(ListNode* head);
	ListNode* reverseN(ListNode* head, int n);
	ListNode* reverseBetween(ListNode* head, int m, int n);
	ListNode* removeElements(ListNode* head, int val);
	ListNode* mergeTwoSortedLists(ListNode* l1, ListNode* l2);
	ListNode* middleNode(ListNode* head);
	ListNode* reversekGroup(ListNode* head, int k);
	bool isPalindromeList(ListNode* head);
	ListNode* quickSortList(ListNode* head);
	ListNode* mergeSortList(ListNode* head);
}

#endif
