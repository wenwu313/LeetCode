ListNode* rotateRight(ListNode* head, int k) {
    if (head == NULL) return NULL;
    int size = 0;
    ListNode *p1 = head, *p2 = head;
    while (p1) {
        size++;
        p1 = p1->next;
    }
    k = k%size;
    p1 = head;
    for (int i = 0; i < k; i++) {
        p2 = p2->next;
    }
    while (p2->next) {
        p1 = p1->next;
        p2 = p2->next;
    }
    p2->next = head;
    head = p1->next;
    p1->next = NULL;
    return head;
}

ListNode* rotateRight2(ListNode* head, int k) {
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