

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

ListNode* mergeKLists(vector<ListNode*>& lists, int begin, int end) {
	if (begin == end)
		return lists[begin];
	int mid = (begin + end) >> 1;
	ListNode *left = mergeKLists(lists, begin, mid);
	ListNode *right = mergeKLists(lists, mid + 1, end);
	return merge(left, right);
}

ListNode* mergeKLists(vector<ListNode*>& lists) {
	if (lists.empty())  return NULL;
	ListNode *head = mergeKLists(lists, 0, lists.size() - 1);
	return head;
}


//·½·¨¶þ
ListNode *mergeKLists(vector<ListNode *> &lists) {
	if (lists.empty()){
		return nullptr;
	}
	while (lists.size() > 1){
		lists.push_back(mergeTwoLists(lists[0], lists[1]));
		lists.erase(lists.begin());
		lists.erase(lists.begin());
	}
	return lists.front();
}
ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
	if (l1 == nullptr){
		return l2;
	}
	if (l2 == nullptr){
		return l1;
	}
	if (l1->val <= l2->val){
		l1->next = mergeTwoLists(l1->next, l2);
		return l1;
	}
	else{
		l2->next = mergeTwoLists(l1, l2->next);
		return l2;
	}
}

