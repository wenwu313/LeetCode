#include<iostream>
#include<algorithm>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int depth(TreeNode* root)
{
	if (root == NULL) return 0;
	return max(depth(root->left), depth(root->right)) + 1;
}

bool isBalanced(TreeNode* root) {
	if (!root) return true;
	if (abs(depth(root->left) - depth(root->right)) > 1)
		return false;
	return isBalanced(root->left) && isBalanced(root->right);
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
	int a[] = { 2, 3, 3, 4, 5, 5, -1, 8 };  
	int size = sizeof(a) / sizeof(int);
	TreeNode* root = creatBTree(a, 0, size);
	cout << isBalanced(root) << endl;
	cin.get();
	return 0;
}
