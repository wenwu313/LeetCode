//Merge two sorted linked lists and return it as a new list. 
ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    if (NULL == l1) return l2;
    if (NULL == l2) return l1;
    ListNode *head = NULL;
    if (l1->val < l2->val) { head = l1; l1 = l1->next; }
    else { head = l2; l2 = l2->next; }
    ListNode *cur = head;

    while (l1 && l2) {
        if (l1->val > l2->val) {
            cur->next = l2;
            l2 = l2->next;
        }
        else {
            cur->next = l1;
            l1 = l1->next;
        }
        cur = cur->next;
    }

    if (l1)  cur->next = l1;
    else    cur->next = l2;
    return head;
}