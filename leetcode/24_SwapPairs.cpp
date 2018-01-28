ListNode* swapPairs(ListNode* head) {
	if (head == NULL) return head;
	ListNode *curr1 = head, *curr2 = head->next;
	while (curr1 != NULL && curr2 != NULL){
		swap(curr1->val, curr2->val);
		if (curr2->next){
			curr1 = curr2->next;
			curr2 = curr1->next;
		}
		else break;
	}
	return head;
}
