ListNode *detectCycle(ListNode *head) {
	if (!head) return NULL;
	ListNode *pslow = head, *pfast = head;
	while (pfast->next && pfast->next->next)
	{
		pfast = pfast->next->next;
		pslow = pslow->next;
		if (pfast == pslow){
			pslow = head;
			while (pfast != pslow){
				pfast = pfast->next;
				pslow = pslow->next;
			}
			return pfast;
		}
	}
	return NULL;
}