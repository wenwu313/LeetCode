#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* sortedListToBST(ListNode* head) {
	if (!head) return NULL;
	if (!head->next){
		TreeNode *root = new TreeNode(head->val);
		return root;
	}			
	ListNode *pfast = head->next, *pslow = head, *head2;
	while (pfast->next && pfast->next->next){
		pfast = pfast->next->next;
		pslow = pslow->next;
	}
	head2 = pslow->next->next;
	TreeNode *root = new TreeNode(pslow->next->val);
	pslow->next = NULL;
	root->left = sortedListToBST(head);
	root->right = sortedListToBST(head2);
	return root;
}

TreeNode* sortedListToBST(ListNode* head) {
	if (head == NULL)
		return NULL;
	ListNode *fast = head;
	ListNode *slow = head;
	ListNode *prev = NULL;
	while (fast && fast->next)
	{
		fast = fast->next->next;
		prev = slow;
		slow = slow->next;
	}
	TreeNode *root = new TreeNode(slow->val);
	if (prev)
		prev->next = NULL;
	else
		head = NULL;
	root->left = sortedListToBST(head);
	root->right = sortedListToBST(slow->next);
	return root;
}

vector<vector<int>> levelOrder(TreeNode* root) {
	vector<vector<int>> result;
	queue<TreeNode*> que;
	if (!root) return result;
	que.push(root);
	while (!que.empty()){
		int size = que.size();
		vector<int> row;
		while (size-- > 0){
			TreeNode *temp = que.front();
			que.pop();
			row.push_back(temp->val);
			if (temp->left)
				que.push(temp->left);
			if (temp->right)
				que.push(temp->right);
		}
		result.push_back(row);
	}
	return result;
}

ListNode* createList(int arr[], int size)
{
	if (size <= 0) return NULL;
	ListNode *list = new ListNode(arr[0]);
	ListNode *cur = list;
	for (int i = 1; i < size; i++){
		cur->next = new ListNode(arr[i]);
		cur = cur->next;
	}
	return list;
}

int main()
{
	int a1[] = { 1, 2, 3, 4, 5, 6, 7 };
    int size1 = sizeof(a1) / sizeof(int);
	ListNode *l1 = createList(a1, size1);
	TreeNode* root = sortedListToBST(l1);
	vector<vector<int>> ans = levelOrder(root);
	for (int i = 0; i < ans.size(); i++){
		for (int j = 0; j < ans[i].size(); j++){
			cout << ans[i][j] << ' ';
		}
		cout << endl;
	}
	cin.get();
	return 0;
}