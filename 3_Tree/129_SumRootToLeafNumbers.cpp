#include<iostream>
#include<vector>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
//=============================================================
void sumNumbers(TreeNode* root, int num, int &result) {
	num = num * 10 + root->val;
	if (!root->left && !root->right){
		result += num;
	}
	if (root->left)
		sumNumbers(root->left, num, result);
	if (root->right)
		sumNumbers(root->right, num, result);
}

int sumNumbers(TreeNode* root) {
	if (!root) return 0;
	int num = 0;
	int result = 0;
	sumNumbers(root, num, result);
	return result;
}
//================================================================
int sum(TreeNode* n, int s){
	if (!n) return 0;
	if (!n->right && !n->left) return s * 10 + n->val;
	return sum(n->left, s * 10 + n->val) + sum(n->right, s * 10 + n->val);
}

int sumNumbers(TreeNode* root) {
	return sum(root, 0);
}
//=================================================================
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
	int a[] = { 1, 0};
	int size = sizeof(a) / sizeof(int);
	TreeNode* root = creatBTree(a, 0, size);
	cout << sumNumbers(root) << endl;
	cin.get();
	return 0;
}
