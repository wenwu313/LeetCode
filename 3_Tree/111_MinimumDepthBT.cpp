#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void minDepth(TreeNode* root, int depth,int &result)
{
	depth += 1;
	if (!root->left && !root->right){
		if (depth < result)
			result = depth;
	}	
	if (root->left)
		minDepth(root->left, depth, result);
	if (root->right)
		minDepth(root->right, depth, result);
	depth -= 1;
}

int minDepth(TreeNode* root) {	
	if (!root) return 0;
	int result = INT_MAX;
	minDepth(root, 0, result);
	return result;
}

int minDepth(TreeNode* root) {
	if (!root) return 0;
	int L = minDepth(root->left), R = minDepth(root->right);
	return 1 + (min(L, R) ? min(L, R) : max(L, R));
}

int minDepth(TreeNode* root) {
	if (!root) return 0;
	int L = minDepth(root->left), R = minDepth(root->right);
	return 1 + (L && R ? min(L, R) : max(L, R));
}

int minDepth(TreeNode *root) {
	if (!root) return 0;
	if (!root->left) return 1 + minDepth(root->right);
	if (!root->right) return 1 + minDepth(root->left);
	return 1 + min(minDepth(root->left), minDepth(root->right));
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
	int a[] = { 5, 4, 8, 11, -1, 13, 4, 7, 2, -1, -1, -1, -1, 5, 1 };
	int size = sizeof(a) / sizeof(int);
	TreeNode* root = creatBTree(a, 0, size);
	cout << minDepth(root) << endl;
	cin.get();
	return 0;
}
