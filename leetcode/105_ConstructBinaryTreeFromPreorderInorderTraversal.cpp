#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder, int ps, int pe, int is, int ie)
{
	if (ps > pe) return NULL;
	TreeNode *root = new TreeNode(preorder[ps]);
	int x;
	for (int i = is; i <= ie; i++){
		if (inorder[i] == root->val){
			x = i;
			break;
		}
	}
	root->left = buildTree(preorder, inorder, ps + 1, ps + x - is, is, x - 1);
	root->right = buildTree(preorder, inorder, pe - ie + x + 1, pe, x + 1, ie);
	return root;
}

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
	return buildTree(preorder, inorder, 0, preorder.size() - 1, 0, inorder.size() - 1);
}

void Print(TreeNode* p)  //Ç°Ðò±éÀú
{
	if (NULL == p)
		return;
	cout << p->val << endl;
	Print(p->left);
	Print(p->right);
}

int main()
{
	vector<int> preorder = { 1, 3, 5, 2, 4, 6 };
	vector<int> inorder = { 5, 3, 1, 4, 2, 6 };
	TreeNode* root = buildTree(preorder, inorder);
	Print(root);
	cin.get();
	return 0;
}
