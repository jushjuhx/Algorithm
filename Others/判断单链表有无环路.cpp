//测试链表有无环路
#include<iostream>
using namespace std;
struct ListNode {
	int val;
	ListNode * next;
	ListNode(int a) :val(a), next(NULL) {}
};
void HasCircle(ListNode * p) {
	ListNode *p1, *p2, *p3, *pf;
	p1 = pf = p;
	p2 = p3 = p->next;
	p1->next = NULL;
	while (1) {
		cout << p1->val << endl;
		if (p3 == NULL)
			break;
		p3 = p3->next;
		p2->next = p1;
		p1 = p2;
		p2 = p3;
	}
	if (p1 == pf) {
		cout << "有环" << endl;
	}
	else {
		cout << "无环" << endl;
	}
}
int main() {
	ListNode a0 = { 0 } , a1 = { 1 }, a2 = { 2 }, a3 = { 3 }, a4 = { 4 };
	ListNode * p = &a0;
	a0.next = &a1;
	a1.next = &a2;
	a2.next = &a3;
	a3.next = &a4;
	//a4.next = &a2;  是否设置环
	HasCircle(p);
}