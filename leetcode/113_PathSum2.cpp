class Solution1 {
public:
    void pathSumFunc(TreeNode* root, int sum, vector<int> &path, vector<vector<int>> &res) {
        path.push_back(root->val);
        sum -= root->val;
        if (!sum && !root->left && !root->right)
            res.push_back(path);
        if (root->left)
            pathSumFunc(root->left, sum, path, res);
        if (root->right)
            pathSumFunc(root->right, sum, path, res);
        path.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> res;
        if (!root) return res;
        vector<int> path;
        pathSumFunc(root, sum, path, res);
        return res;
    }
};

class Solution2 {
public:
    void pathSum(TreeNode* root, int sum, vector<int> &path, vector<vector<int>> &res)
    {
        if (!root) return;
        path.push_back(root->val);
        sum -= root->val;
        if (sum == 0 && !root->left && !root->right)
            res.push_back(path);
        pathSum(root->left, sum, path, res);
        pathSum(root->right, sum, path, res);
        path.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> ans;
        vector<int> path;
        pathSum(root, sum, path, ans);
        return ans;
    }
};