bool hasCycle(ListNode *head) {
    if (!head) return false;
    ListNode *pslow = head, *pfast = head;
    while (pfast->next && pfast->next->next)
    {
        pfast = pfast->next->next;
        pslow = pslow->next;
        if (pfast == pslow) {
            return true;
        }
    }
    return false;
}