
#include<iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode* deleteDuplicates(ListNode* head) {  //自己写的
	if (head == NULL || head->next == NULL) return head;
	ListNode *curr = head;
	ListNode *pre = new ListNode(-1);
	pre->next = head;
	head = pre;
	while (curr && curr->next){
		if (curr->val == curr->next->val){
			int base = curr->val;
			curr = curr->next;
			while (curr && (curr->val == base)){
				ListNode *tmp2 = curr;
				curr = curr->next;
				delete tmp2;
			}
			pre->next = curr;
		}
		else{
			curr = curr->next;
			pre = pre->next;
		}
	}
	return head->next;
}

ListNode* deleteDuplicates(ListNode* head) {  //比较经典的
	ListNode* dummy = new ListNode(0);
	dummy->next = head;
	ListNode* cur = dummy;
	int duplicate;
	while (cur->next && cur->next->next) {
		if (cur->next->val == cur->next->next->val) {
			duplicate = cur->next->val;
			while (cur->next && cur->next->val == duplicate) {
				cur->next = cur->next->next;
			}
		}
		else {
			cur = cur->next;
		}
	}
	return dummy->next;
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
	int a1[] = { 2, 2, 2, 3, 3, 5 };
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