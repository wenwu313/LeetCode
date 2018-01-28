//two non-empty linked lists,add two number
//Input: (2 -> 4 -> 3) + (5 -> 6 -> 4) Output: 7 -> 0 -> 8

#include<iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
	ListNode preNode(-1), *cur = &preNode;	
	int more = 0;
	while (l1 || l2 || more){
		more += (l1 ? l1->val : 0) + (l2 ? l2->val : 0);
		cur->next = new ListNode(more % 10);
		cur = cur->next;
		if (l1) l1 = l1->next;
		if (l2) l2 = l2->next;
		more = more / 10;
	}
	return preNode.next;
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
	int a1[] = { 2, 4, 3 };
	int a2[] = { 5, 6, 4 };
	int size1 = sizeof(a1) / sizeof(int), size2 = sizeof(a2) / sizeof(int);
	ListNode *l1 = createList(a1, size1);
	ListNode *l2 = createList(a2, size2);
	ListNode *l3 = addTwoNumbers(l1, l2);
	printList(l3);
	cin.get();
	return 0;
}