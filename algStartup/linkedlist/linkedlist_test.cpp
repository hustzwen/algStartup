#include "algStartup/linkedlist/csrc/linkedlist.h"
#include <iostream>

using namespace algstartup;

int main(int argc, char** argv){

	/* reverse, delete  */
	ListNode *A = new ListNode(3);
	ListNode *B = new ListNode(2);
	ListNode *C = new ListNode(1);
	ListNode *D = new ListNode(4);
	ListNode *E = new ListNode(9);
	ListNode *F = new ListNode(6);
	ListNode *G = new ListNode(7);

	ListNode *head1 = A;
	A->next = C;
	C->next = E;
	E->next = G;
	ListNode *head2 = B;
	B->next = D;
	D->next = F;

	//printList(reverseBetween(head1, 3, 4));
	//printList(reversekGroup(head1, 3));
	printList(quickSortList(head1));

	///* merge */
	//ListNode* mergeList = mergeTwoSortedLists(head1, head2);
	//printList(mergeList);
	
	
	delete A, A = nullptr;
	delete B, B = nullptr;
	delete C, C = nullptr;
	delete D, D = nullptr;
	delete E, E = nullptr;
	delete F, F = nullptr;
	delete G, G = nullptr;

	//mergeList = nullptr;

	system("pause");
	return 0;
}