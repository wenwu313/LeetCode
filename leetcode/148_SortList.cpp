//Merge two sorted linked lists and return it as a new list. 

#include<iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode* merge(ListNode* left, ListNode* right)
{
	if (left == NULL) return right;
	if (right == NULL) return left;
	ListNode *result = NULL;
	if (left->val < right->val){
		result = left;
		left = left->next;
	}
	else{
		result = right;
		right = right->next;
	}
	ListNode *curr = result;

	while (left && right){
		if (left->val < right->val){
			curr->next = left;
			left = left->next;
		}
		else{
			curr->next = right;
			right = right->next;
		}
		curr = curr->next;
	}

	curr->next = left ? left : right;
	return result;
}


ListNode* sortList(ListNode* head) {
	if (head == NULL || head->next == NULL) return head;	
	ListNode *pslow = head;
	ListNode *pfast = head;
	while (pfast->next && pfast->next->next){
		pslow = pslow->next;
		pfast = pfast->next->next;
	}
	ListNode *rhalf = pslow->next;
	pslow->next = NULL;
	return merge(sortList(head), sortList(rhalf));
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
	int a1[] = { 7, 4, 3, 1, 5 };
	//int a2[] = { 1, 3, 5 };
	int size1 = sizeof(a1) / sizeof(int);
	//int size2 = sizeof(a2) / sizeof(int);
	ListNode *l1 = createList(a1, size1);
	//ListNode *l2 = createList(a2, size2);
	ListNode *l3 = sortList(l1);
	printList(l3);
	cin.get();
	return 0;
}