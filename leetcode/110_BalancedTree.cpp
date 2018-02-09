class Solution1 {
public:
	bool IsBalanced(TreeNode* pRoot, int &depth){
		if (!pRoot){
			depth = -1;
			return true;
		}
		int left, right;
		if (IsBalanced(pRoot->left, left) && IsBalanced(pRoot->right, right)) {
			int diff = left - right;
			if (diff <= 1 && diff >= -1){
				depth = 1 + (left>right ? left : right);
				return true;
			}
		}
		return false;
	}

	bool isBalanced(TreeNode* root) {
		int depth;
		return IsBalanced(root, depth);
	}
};

class Solution2 {
public:
    bool isBalanced(TreeNode *root) {
        int height=0;
        return isBalancedUtil(root, height);
    }

    bool isBalancedUtil(TreeNode* root, int& height){
       if(root==NULL){
          height=0;
          return true;
       }
       int lh=0, rh=0;
       bool isLeft = isBalancedUtil(root->left, lh);
       bool isRight = isBalancedUtil(root->right, rh);
       height = (lh > rh ? lh : rh) + 1;
       return (abs(lh-rh)<=1 && isLeft && isRight);
    }
};