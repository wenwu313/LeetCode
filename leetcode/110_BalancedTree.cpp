class Solution1 {
public:
    bool IsBalanced(TreeNode* pRoot, int &depth) {
        if (!pRoot) {
            depth = -1;
            return true;
        }
        int left, right;
        if (IsBalanced(pRoot->left, left) && IsBalanced(pRoot->right, right)) {
            int diff = left - right;
            if (diff <= 1 && diff >= -1) {
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
    bool isBalancedFunc(TreeNode *root, int& depth) {
        if (!root) {
            depth = -1;
            return true;
        }
        int left = 0, right = 0;
        bool isLeft = isBalancedFunc(root->left, left);
        bool isRight = isBalancedFunc(root->right, right);
        depth = (left > right ? left : right) + 1;
        return isLeft && isRight && abs(left - right) <= 1;
    }

    bool isBalanced(TreeNode* root) {
        int x = 0;
        return isBalancedFunc(root, x);
    }
};