class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *prehead = new ListNode(-1);
        prehead->next = head;
        head = prehead;
        while (head->next) {
            if (head->next->val == val) {
                ListNode *temp = head->next;
                head->next = head->next->next;
                delete temp;
            }
            else
                head = head->next;
        }
        return prehead->next;
    }

    ListNode* removeElements1(ListNode* head, int val) {
        ListNode *fakeHead = new ListNode(-1);
        fakeHead->next = head;
        ListNode *curr = head, *prev = fakeHead;
        while (curr) {
            if (curr->val == val) {
                prev->next = curr->next;
            }
            else {
                prev = prev->next;
            }
            curr = curr->next;
        }
        return fakeHead->next;
    }
};