
class Solution1 {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *cur1 = new ListNode(-1), *cur2 = cur1;
        cur1->next = head;
        head = cur1;
        for (int i = 0; i < n; i++) {
            cur2 = cur2->next;
        }
        while (cur2->next) {
            cur1 = cur1->next;
            cur2 = cur2->next;
        }
        ListNode* temp = cur1->next;
        cur1->next = cur1->next->next;
        delete temp;
        return head->next;
    }
};


class Solution2 {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (head == NULL) return NULL;
        ListNode *p1 = head, *pPre = NULL;
        ListNode *p2 = head;
        for (int i = 0; i < n - 1; i++)  p2 = p2->next;
        while (p2->next) {
            pPre = p1;
            p1 = p1->next;
            p2 = p2->next;
        }
        if (pPre == NULL) {
            head = p1->next;
            delete p1;
        }
        else {
            pPre->next = p1->next;
            delete p1;
        }
        return head;
    }
};