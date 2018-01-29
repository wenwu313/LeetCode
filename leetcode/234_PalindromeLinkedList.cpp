class Solution {  
public:  
    ListNode *reverseList(ListNode *head){  
        ListNode *pre = NULL, *temp;  
        while(head){  
            temp = head->next;  
            head->next = pre;  
            pre = head;  
            head = temp;  
        }  
        return pre;  
    }  
  
    bool isPalindrome(ListNode* head) {  
        if(!head || !head->next) return true;  
        ListNode *slow = head,*fast = head;  
        while(fast && fast->next){  
            fast = fast->next->next;  
            slow = slow->next;  
        }  
        if(fast){//链表个数为奇数个  
            slow = reverseList(slow->next);  
        }  
        else{//链表个数为偶数个  
            slow = reverseList(slow);  
        }  
        while(slow){  
            if(head->val != slow->val)  
                return false;  
            head = head->next;  
            slow = slow->next;  
        }  
        return true;  
    }  
};  

//class Solution {
//public:
//  ListNode *reverseList(ListNode *head){
//      ListNode *pre = NULL, *temp;
//      while (head){
//          temp = head->next;
//          head->next = pre;
//          pre = head;
//          head = temp;
//      }
//      return pre;
//  }
//
//  bool isPalindrome(ListNode* head) {
//      if (!head || !head->next) return true;
//      ListNode *slow = head, *fast = head, *pre = NULL;
//      while (fast && fast->next){
//          fast = fast->next->next;
//          pre = slow;
//          slow = slow->next;
//      }
//      pre->next = NULL;
//      slow = reverseList(slow);
//      while (head && slow){
//          if (head->val != slow->val)
//              return false;
//          head = head->next;
//          slow = slow->next;
//      }
//      return true;
//  }
//}; 

