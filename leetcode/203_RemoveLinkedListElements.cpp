#include<iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode* removeElements(ListNode* head, int val) {
	ListNode *prehead = new ListNode(-1);
	prehead->next = head;
	head = prehead;
	while (head->next){
		if (head->next->val == val){
			ListNode *temp = head->next;
			head->next = head->next->next;
			delete temp;
		}
		else
			head = head->next;
	}
	return prehead->next;
}

ListNode* removeElements(ListNode* head, int val) {
	ListNode *fakeHead = new ListNode(-1);
	fakeHead->next = head;
	ListNode *curr = head, *prev = fakeHead;
	while (curr) {
		if (curr->val == val) {
			prev->next = curr->next;
		}
		else {
			prev = prev->next;
		}
		curr = curr->next;
	}
	return fakeHead->next;
}

ListNode *removeElements(ListNode *head, int val)
{
	ListNode **list = &head;
	while (*list != nullptr)
	{
		if ((*list)->val == val)
			*list = (*list)->next;	
		else
			list = &(*list)->next;
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
	//int a2[] = { 1, 3, 5 };
	//int size2 = sizeof(a2) / sizeof(int);
	//ListNode *l2 = createList(a2, size2);
	int a1[] = { 1, 2, 6, 3, 4, 5, 6 };
	int size1 = sizeof(a1) / sizeof(int);
	ListNode *l1 = createList(a1, size1);
	ListNode *l3 = removeElements(l1, 6);
	printList(l3);
	cin.get();
	return 0;
}