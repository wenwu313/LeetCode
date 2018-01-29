class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode *pre = new ListNode(-1);
        pre->next = head;
        head=pre;
        for(int i=0;i<m-1;i++)
           pre=pre->next;
        ListNode *cur=pre->next;
        for(int i=0;i<n-m;i++){
            ListNode *move = cur->next;
            cur->next = move->next;
            move->next= pre->next;
            pre->next = move;
        }
        return head->next;
    }
};