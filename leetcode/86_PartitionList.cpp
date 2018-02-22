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
    ListNode* partition(ListNode* head, int x) {
        if (!head) return NULL;
        ListNode *head1 = new ListNode(-1);
        head1->next = head;
        head = head1;
        ListNode *head2 = new ListNode(-1);
        ListNode *cur = head2;
        while (head1->next) {
            if (head1->next->val >= x) {
                cur->next = head1->next;
                cur = cur->next;
                head1->next = head1->next->next;
            }
            else
                head1 = head1->next;
        }
        cur->next = NULL;
        head1->next = head2->next;
        return head->next;
    }
};