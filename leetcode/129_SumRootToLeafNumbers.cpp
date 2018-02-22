class Solution1 {
public:
    void sumNumbersFunc(TreeNode* root, int num, int &result) {
        num = num * 10 + root->val;
        if (!root->left && !root->right)
            result += num;
        if (root->left)
            sumNumbersFunc(root->left, num, result);
        if (root->right)
            sumNumbersFunc(root->right, num, result);
    }

    int sumNumbers(TreeNode* root) {
        if (!root) return 0;
        int result = 0;
        sumNumbersFunc(root, 0, result);
        return result;
    }
};

class Solution2 {
public:
    int sumNumbers(TreeNode *root) {

        if (!root) return 0;
        int sum = 0;
        vector<TreeNode*> v;
        v.push_back(root);
        while (v.size()>0) {
            TreeNode* node = v.back();
            v.pop_back();
            if (node->left) {
                node->left->val += (10 * node->val);
                v.push_back(node->left);
            }
            if (node->right) {
                node->right->val += (10 * node->val);
                v.push_back(node->right);
            }
            if (!node->right && !node->left) {
                sum += node->val;
            }
        }

        return sum;
    }
};
