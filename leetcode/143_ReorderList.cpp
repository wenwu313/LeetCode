//Merge two sorted linked lists and return it as a new list. 

#include<iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

void reorderList(ListNode* head) {
	if (head == NULL || head->next == NULL) return ;
	ListNode *pslow = head;
	ListNode *pfast = head;
	while (pfast->next && pfast->next->next){
		pslow = pslow->next;
		pfast = pfast->next->next;
	}
	ListNode *last= pslow->next;
	pslow->next = NULL;

	ListNode *pre = NULL;
	while (last){
		ListNode *post = last->next;
		last->next = pre;
		pre = last;
		last = post;
	}

	ListNode *node1 = head, *node2 = pre;
	while (node2 != NULL){
		ListNode *tmp1 = node1->next;
		ListNode *tmp2 = node2->next;
		node1->next = node2;
		node2->next = tmp1;
		node1 = tmp1;
		node2 = tmp2;
	}
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
	int a1[] = { 7, 4, 3, 1 ,6};
	//int a2[] = { 1, 3, 5 };
	int size1 = sizeof(a1) / sizeof(int);
	//int size2 = sizeof(a2) / sizeof(int);
	ListNode *l1 = createList(a1, size1);
	//ListNode *l2 = createList(a2, size2);
	reorderList(l1);
	printList(l1);
	cin.get();
	return 0;
}