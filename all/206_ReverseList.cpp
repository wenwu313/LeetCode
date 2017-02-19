ListNode* reverseList1(ListNode* head) {
	if (head == NULL) return NULL;
	ListNode *pNext, *pPre = NULL, *curr = head;
	while (curr->next){
		pNext = curr->next;
		curr->next = pPre;
		pPre = curr;
		curr = pNext;
	}
	curr->next = pPre;
	return curr;
}

ListNode* reverseList(ListNode* head) {
	if (head == NULL) return NULL;
	ListNode *pNext, *pPre = NULL;
	while (head->next){
		pNext = head->next;
		head->next = pPre;
		pPre = head;
		head = pNext;
	}
	head->next = pPre;
	return head;
}

ListNode* reverseList(ListNode* head) {  //ตÝน้
	if (!head || !(head->next)) return head;
	ListNode* node = reverseList(head->next);
	head->next->next = head;
	head->next = NULL;
	return node;
}