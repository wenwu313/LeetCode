ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
	int sizeA = 0, sizeB = 0;
	ListNode *temp1 = headA, *temp2 = headB;
	while (temp1){
		temp1 = temp1->next;
		sizeA++;
	}
	while (temp2){
		temp2 = temp2->next;
		sizeB++;
	}
	if (sizeA < sizeB)
		return getIntersectionNode(headB, headA);
	sizeA = sizeA - sizeB;
	while (sizeA-->0){
		headA = headA->next;
	}
	temp1 = headA, temp2 = headB;
	while (temp1){
		if (temp1 == temp2)
			return temp1;
		temp1 = temp1->next;
		temp2 = temp2->next;
	}
	return NULL;
}

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    ListNode *cur1 = headA, *cur2 = headB;
    while(cur1 != cur2){
        cur1 = cur1?cur1->next:headB;
        cur2 = cur2?cur2->next:headA;
    }
    return cur1;
}