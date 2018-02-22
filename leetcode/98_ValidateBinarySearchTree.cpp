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
    //输出中序遍历结果 看其是否递增
    void inorder(TreeNode* root, vector<int> &nums)
    {
        if (root == NULL) return;
        inorder(root->left, nums);
        nums.push_back(root->val);
        inorder(root->right, nums);
    }

    bool isValidBST(TreeNode* root) {
        if (!root) return true;
        vector<int> nums;
        inorder(root, nums);
        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums[i] >= nums[i + 1])
                return false;
        }
        return true;
    }
};