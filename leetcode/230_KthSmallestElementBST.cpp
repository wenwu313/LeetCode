class Solution {
public:
	int kthSmallest(TreeNode* root, int k) {
		stack<TreeNode*> stack;
		while (root || !stack.empty()){
			if (root){
				stack.push(root);
				root = root->left;
			}
			else{
				root = stack.top();
				stack.pop();
				if (--k == 0)
					break;
				root = root->right;
			}

		}
		return root->val;
	}
};