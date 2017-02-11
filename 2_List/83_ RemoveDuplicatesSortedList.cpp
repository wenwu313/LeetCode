
#include<iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode* deleteDuplicates(ListNode* head) {
	if (head == NULL || head->next == NULL) return head;
	ListNode *curr = head->next, *pre = head;
	while (curr){
		if (curr->val == pre->val){
			ListNode *temp = curr;
			pre->next = curr->next;
			curr = curr->next;
			delete temp;
		}
		else{
			pre = curr;
			curr = curr->next;
		}
	}
	return head;
}

ListNode* deleteDuplicates1(ListNode* head) {
	if (head) {
		ListNode *p = head;
		while (p->next) {
			if (p->val != p->next->val) {
				p = p->next;
			}
			else {
				ListNode *tmp = p->next;
				p->next = p->next->next;
				free(tmp);
			}
		}
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
	int a1[] = { 1, 1, 2, 3, 3 };
	//int a2[] = { 1, 3, 5 };
	int size1 = sizeof(a1) / sizeof(int);
	//int size2 = sizeof(a2) / sizeof(int);
	ListNode *l1 = createList(a1, size1);
	//ListNode *l2 = createList(a2, size2);
	ListNode *l3 = deleteDuplicates(l1);
	printList(l3);
	cin.get();
	return 0;
}