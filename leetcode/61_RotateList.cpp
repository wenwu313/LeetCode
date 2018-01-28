
#include<iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode* rotateRight(ListNode* head, int k) {
	if (head == NULL) return NULL;
	int size = 0;
	ListNode *p1 = head, *p2 = head;
	while (p1){
		size++;
		p1 = p1->next;
	}
	k = k%size;
	p1 = head;
	for (int i = 0; i < k; i++){
		p2 = p2->next;
	}
	while (p2->next){
		p1 = p1->next;
		p2 = p2->next;
	}
	p2->next = head;
	head = p1->next;
	p1->next = NULL;
	return head;
}

ListNode* rotateRight(ListNode* head, int k) {
	if (!head) return head;

	int len = 1; // number of nodes
	ListNode *newH, *tail;
	newH = tail = head;

	while (tail->next)  // get the number of nodes in the list
	{
		tail = tail->next;
		len++;
	}
	tail->next = head; // circle the link

	if (k %= len)
	{
		for (auto i = 0; i<len - k; i++) tail = tail->next; // the tail node is the (len-k)-th node (1st node is head)
	}
	newH = tail->next;
	tail->next = NULL;
	return newH;
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
	ListNode *l3 = rotateRight(l1,2);
	printList(l3);
	cin.get();
	return 0;
}