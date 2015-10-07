//
//You are given two linked lists representing two non - negative numbers.
//The digits are stored in reverse order and each of their nodes contain a single digit.
//Add the two numbers and return it as a linked list.
//两个链表相加，大于等于10进位
//Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
//	Output : 7 -> 0 -> 8

#include <iostream>
using namespace std;


struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
//主要思想:把两个链表共有长度的部分相加，并进位，直到到了某个链表的末尾，把长链表合并到已经相加的链表后面，同时如果有进位则进位
class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		int tmp1 = 0;
		int tmp2 = 0;
		ListNode * p1 = NULL;
		ListNode * p = l1;
		while (NULL != l1 && NULL != l2) {
			tmp2 = l1->val + l2->val + tmp1;
			if (tmp2 >= 10) {
				tmp2 -= 10;
				tmp1 = 1;
			}
			else {
				tmp1 = 0;
			}
			l1->val = tmp2;
			p1 = l1;
			l1 = l1->next;
			l2 = l2->next;
		}
		if (NULL == l1 && NULL == l2) {
			if (tmp1 == 1) {
				ListNode* p2 = new ListNode(1);
				p1->next = p2;
			}
		}
		else {
			if (NULL == l1)
				p1->next = l2;
			if (tmp1 == 1) {
				p1 = p1->next;
				p1->val += 1;
				while (p1->val >= 10) {
					p1->val -= 10;
					if (NULL == p1->next) {
						ListNode* p2 = new ListNode(1);
						p1->next = p2;
						break;
					}
					else {
						p1 = p1->next;
						p1->val += 1;
					}
				}
			}
		}
		return p;
	}
};
//int main() {
//	ListNode a1 = { 2 }, a2 = { 4 }, a3 = { 3 };
//	ListNode b1 = { 5 }, b2 = { 6 }, b3 = { 4 };
//	ListNode * l1 = &a1;
//	ListNode * l2 = &b1;
//	l1->next = &a2;
//	a2.next = &a3;
//	l2->next = &b2;
//	b2.next = &b3;
//	Solution *a = new Solution();
//	ListNode * p = a->addTwoNumbers(l1, l2);
//	while (NULL != p) {
//		cout << p->val << endl;
//		p = p->next;
//	}
//}
int main() {
	ListNode a1 = { 8 }, a2 = { 9 }, a3 = { 9 }, a4 = { 9 };
	ListNode b1 = { 2 };
	ListNode * l1 = &a1;
	ListNode * l2 = &b1;
	l1->next = &a2;
	a2.next = &a3;
	a3.next = &a4;
	Solution *a = new Solution();
	ListNode * p = a->addTwoNumbers(l2, l1);
	while (NULL != p) {
		cout << p->val << endl;
		p = p->next;
	}
}