/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
*/
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head)
            return NULL;
        ListNode *cur = new ListNode(-1);
        cur->next = head;
        head = cur;
        while (cur->next && cur->next->next) {
            if (cur->next->val == cur->next->next->val) {
                int temp = cur->next->val;
                while (cur->next && cur->next->val == temp) {
                    cur->next = cur->next->next;
                }
            }
            else
                cur = cur->next;
        }
        return head->next;
    }
};