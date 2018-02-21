class Solution {
public:
	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder, int ps, int pe, int is, int ie){
		if (ps > pe) return NULL;
		TreeNode *root = new TreeNode(preorder[ps]);
		int x;
		for (int i = is; i <= ie; i++) {
			if (inorder[i] == root->val) {
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
};