#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<algorithm>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void flatten(TreeNode* root) {   //my
	if (!root) return;
	stack<TreeNode*>  stack;
	stack.push(root);
	TreeNode* cur = new TreeNode(-1);
	cur->right = root;
	root = cur;
	while (!stack.empty()){
		TreeNode *temp = stack.top();
		cur->right = temp;
		cur->left = NULL;
		cur = cur->right;
		stack.pop();
		if (temp->right)
			stack.push(temp->right);
		if (temp->left)
			stack.push(temp->left);	
	}
	root = root->right;
}

void flatten(TreeNode* root) {
	if (!root) return;
	stack<TreeNode*>  stack;
	stack.push(root);
	while (!stack.empty()){
		TreeNode *temp = stack.top();
		stack.pop();
		if (temp->right)
			stack.push(temp->right);
		if (temp->left)
			stack.push(temp->left);
		if (!stack.empty())
			temp->right = stack.top();
		    temp->left = NULL;
	}
}

void flatten(TreeNode* root) {
	if (root == NULL) return;
	TreeNode *left = root->left;
	TreeNode *right = root->right;
	root->left = NULL;
	flatten(left);
	flatten(right);
	root->right = left;
	TreeNode *cur = root;
	while (cur->right != NULL) cur = cur->right;
	cur->right = right;
}

void flatten(TreeNode *root) {
	TreeNode *now = root;
	while (now){   
		if (now->left){
			TreeNode* pre = now->left;
			while (pre->right)
				pre = pre->right;		
			pre->right = now->right;
			now->right = now->left;
			now->left = NULL;
		}
		now = now->right;
	}
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

TreeNode* creatBTree(int data[], int index, int n)
{
	TreeNode *pNode = NULL;
	if (index < n && data[index]!=-1)  
	{
		pNode = new TreeNode(data[index]);
		pNode->left = creatBTree(data, 2 * index + 1, n);  
		pNode->right = creatBTree(data, 2 * index + 2, n);
	}
	return pNode;
}

int main()
{
	int a[] = { 1, 2, 5, 3, 4, -1, 6 };
	int size = sizeof(a) / sizeof(int);
	TreeNode* root = creatBTree(a, 0, size);
	flatten(root);
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
