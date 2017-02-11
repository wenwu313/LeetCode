
#include<iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode* reverseBetween(ListNode* head, int m, int n) {
	ListNode *pre = new ListNode(-1);
	pre->next = head;
	head = pre;
	ListNode *p1 = head, *p2 = head;
	while (m != 0 && p1->next != NULL){
		pre = p1;
		p1 = p1->next;
		m--;
	}
	while (n != 0 && p2->next != NULL){
		p2 = p2->next;
		n--;
	}
	ListNode *pPre = p2->next;
	while (p1 != p2){
		ListNode *pNext = p1->next;
		p1->next = pPre;
		pPre = p1;
		p1 = pNext;
	}
	p2->next = pPre;
	pre->next = p2;
	return head->next;
}

ListNode* reverseBetween(ListNode* head, int m, int n) {
	ListNode* new_head = new ListNode(0);
	new_head->next = head;
	ListNode* pre = new_head;
	for (int i = 0; i < m - 1; i++)
		pre = pre->next;
	ListNode* cur = pre->next;
	for (int i = 0; i < n - m; i++) {
		ListNode* move = cur->next;
		cur->next = move->next;
		move->next = pre->next;
		pre->next = move;
	}
	return new_head->next;
}

ListNode* createList(int arr[], int size)  
{
	if (size <= 0) return NULL;
	ListNode *list = new ListNode(arr[0]);
	ListNode *cur = list;
	for (int i = 1; i < size; i++){
		cur->next = new ListNode(arr[i]);
		cur = cur->next;
	}
	return list;
}

void printList(ListNode* p)
{
	while (p){
		cout << p->val << ' ';
		p = p->next;
	}
	cout << endl;
}

int main()
{
	int a1[] = { 1, 2, 3, 4, 5 };
	//int a2[] = { 1, 3, 5 };
	int size1 = sizeof(a1) / sizeof(int);
	//int size2 = sizeof(a2) / sizeof(int);
	ListNode *l1 = createList(a1, size1);
	//ListNode *l2 = createList(a2, size2);
	ListNode *l3 = reverseBetween(l1, 2, 4);
	printList(l3);
	cin.get();
	return 0;
}