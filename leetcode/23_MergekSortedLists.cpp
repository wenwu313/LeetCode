class Solution {
public:
	ListNode* merge(ListNode *left, ListNode *right){
		ListNode node(-1);
		ListNode *cur = &node;
		while (left && right){
			if (left->val < right->val){
				cur->next = left;
				left = left->next;
			}
			else{
				cur->next = right;
				right = right->next;
			}
			cur = cur->next;
		}
		cur->next = left ? left : right;
		return node.next;
	}

	ListNode* merge1(ListNode *head1, ListNode* head2){
		if (!head1) return head2;
		if (!head2) return head1;
		if (head1->val<head2->val){
			head1->next = merge(head1->next, head2);
			return head1;
		}
		else{
			head2->next = merge(head1, head2->next);
			return head2;
		}
	}

	ListNode* mergeKLists(vector<ListNode*>& lists, int left, int right) {
		if (left>right)  return NULL;  //注释1，去掉这行见注释2
		if (left == right) return lists[left];
		if (left<right){
			int mid = (left + right) >> 1;
			ListNode *head1 = mergeKLists(lists, left, mid);
			ListNode *head2 = mergeKLists(lists, mid + 1, right);
			return merge(head1, head2);
		}
	}

	ListNode* mergeKLists(vector<ListNode*>& lists) {
		return mergeKLists(lists, 0, lists.size() - 1);  //注释2，加上 if (lists.empty())  return NULL;  
	}

	ListNode* mergeKLists1(vector<ListNode *> &lists) {
		ListNode *p, *p1, *p2;
		while (lists.size()>1){
			p1 = lists.back();
			lists.pop_back();
			p2 = lists.back();
			lists.pop_back();
			p = merge(p1, p2);
			lists.insert(lists.begin(), p);
		}
		return lists.size() == 1 ? lists[0] : NULL;

		/* the following method is not fast enough! */
		/*
		ListNode* pHead = NULL;
		for (int i=0; i<lists.size(); i++){
		pHead = mergeTwoLists(pHead, lists[i]);
		}
		return pHead;
		*/
	}
};
