#include<iostream>
#include<stack>
#include<vector>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}	
};

bool isSymmetric(TreeNode* left, TreeNode* right)
{
	if (left == NULL && right == NULL)
		return true;
	if (left == NULL || right == NULL)
		return false;
	else{
		if (left->val != right->val)
			return false;
		else
			return isSymmetric(left->left, right->right) && isSymmetric(left->right, right->left);
	}
}

bool isSymmetric1(TreeNode* root) {  //递归
	if (root == NULL)
		return true;
	else
		return isSymmetric(root->left, root->right);
}

bool isSymmetric(TreeNode* root) {  //迭代
	if (!root)
		return true;
	stack<TreeNode*> stack1;
	stack<TreeNode*> stack2;
	stack1.push(root->left);
	stack2.push(root->right);
	while (!stack1.empty()){
		TreeNode* left = stack1.top();
		TreeNode* right = stack2.top();
		stack1.pop();
		stack2.pop();
		if (!left && !right)
			continue;
		if (!left|| !right )
			return false;
		else{
			if (left->val != right->val)
				return false;
			else{
				stack1.push(left->left);
				stack2.push(right->right);
				stack1.push(left->right);
				stack2.push(right->left);
			}
		}
	}
	return true;
}

TreeNode* creatBTree(int data[], int index, int n)
{
	TreeNode *pNode = NULL;
	if (index < n && data[index]!=-1)  //-1令树结点为NULL
	{
		pNode = new TreeNode(data[index]);
		pNode->left = creatBTree(data, 2 * index + 1, n);  //将二叉树按照层序遍历, 依次标序号, 从0开始
		pNode->right = creatBTree(data, 2 * index + 2, n);
	}
	return pNode;
}

int main()
{
	int a[] = { 2, 3, 3, 4, 5, 5, -1 };
	//int a[] = { 1, 2, 2, 3, 4, 4, 3 };
	int size = sizeof(a) / sizeof(int);
	TreeNode* root = creatBTree(a, 0, size);
	cout << isSymmetric(root) << endl;
	cin.get();
	return 0;
}
