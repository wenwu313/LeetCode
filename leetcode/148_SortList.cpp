class Solution {
public:
    ListNode *merge(ListNode *head1, ListNode *head2) {
        ListNode *result = new ListNode(-1), *cur = result;
        while (head1 && head2) {
            if (head1->val < head2->val) {
                cur->next = head1;
                head1 = head1->next;
            }
            else {
                cur->next = head2;
                head2 = head2->next;
            }
            cur = cur->next;
        }
        cur->next = head1 ? head1 : head2;
        return result->next;
    }

    ListNode* sortList(ListNode* head) {
        if (!head || !head->next)
            return head;
        ListNode *pslow = head, *pfast = head->next;
        while (pfast && pfast->next) {
            pfast = pfast->next->next;
            pslow = pslow->next;
        }
        ListNode *head2 = pslow->next;
        pslow->next = NULL;
        return merge(sortList(head), sortList(head2));
    }
};