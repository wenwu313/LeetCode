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
        if(!head)
            return NULL;
        ListNode *cur = head;
        while(cur->next){
            if(cur->val==cur->next->val){
                ListNode *temp = cur->next;
                cur->next=cur->next->next;
                delete temp;
            }
            else
                cur=cur->next;        
        }
        return head;
    }
};