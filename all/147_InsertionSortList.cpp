#include<iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode* insertionSortList(ListNode* head) {
	if (!head) return head;
	ListNode *head1 = new ListNode(-1), *head2 = head->next;
	head1->next = head;
	head->next = NULL;
	while (head2){
		head = head1;
		while (head->next && head->next->val <= head2->val)
		{
			head = head->next;
		}
		ListNode *temp = head2->next;
		head2->next = head->next;
		head->next = head2;
		head2 = temp;
	}
	return head1->next;
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
	int a1[] = { 2, 1, 3, 6, 9, 8 };
	int size1 = sizeof(a1) / sizeof(int);
	ListNode *l1 = createList(a1, size1);
	ListNode *l3 = insertionSortList(l1);
	printList(l3);
	cin.get();
	return 0;
}