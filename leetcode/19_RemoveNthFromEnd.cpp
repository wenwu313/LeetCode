//Merge two sorted linked lists and return it as a new list. 

#include<iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode* removeNthFromEnd(ListNode* head, int n) {
	if (head == NULL) return NULL;
	ListNode *p1 = head, *pPre = NULL;
	ListNode *p2 = head;
	for (int i = 0; i < n - 1; i++)  p2 = p2->next;
	while (p2->next){
		pPre = p1;
		p1 = p1->next;
		p2 = p2->next;
	}
	if (pPre == NULL){
		head = p1->next;
		delete p1;
	}		
	else{
		pPre->next = p1->next;
		delete p1;
	}
	return head;
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
	int a1[] = { 2, 3, 4, 5 };
	//int a2[] = { 1, 3, 5 };
	int size1 = sizeof(a1) / sizeof(int);
	//int size2 = sizeof(a2) / sizeof(int);
	ListNode *l1 = createList(a1, size1);
	//ListNode *l2 = createList(a2, size2);
	ListNode *l3 = removeNthFromEnd(l1, 2);
	printList(l3);
	cin.get();
	return 0;
}