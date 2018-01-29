/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };
*/
class Solution {
public:
	vector<TreeNode*> temp;
	void getPath(TreeNode *root, TreeNode *p, vector<TreeNode*> &path){
		temp.push_back(root);
		if (root == p){
			path = temp;
			return;
		}
		if (root->left)
			getPath(root->left, p, path);
		if (root->right)
			getPath(root->right, p, path);
		temp.pop_back();
	}


	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		vector<TreeNode*> pathp, pathq;
		getPath(root, p, pathp);
		temp.clear();
		getPath(root, q, pathq);
		int i = 1;
		while (i<pathp.size() && i<pathq.size()){
			if (pathp[i] != pathq[i])
				break;
			i++;
		}
		return pathp[i - 1];
	}
};