class Solution {
public:
    bool getPath(TreeNode* root, TreeNode* node, vector<TreeNode*> &path) {
        if (root == node) {
            path.push_back(root);
            return true;
        }
        path.push_back(root);
        if (root->left && getPath(root->left, node, path) ||
            root->right && getPath(root->right, node, path))
            return true;
        path.pop_back();
        return false;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root || !p || !q) return NULL;
        vector<TreeNode*> path1;
        vector<TreeNode*> path2;
        getPath(root, p, path1);
        getPath(root, q, path2);

        TreeNode *plast = NULL;
        for (int i = 0; i<path1.size() && i <path2.size(); i++) {
            if (path1[i] == path2[i])
                plast = path1[i];
            else
                break;
        }
        return plast;
    }
};


class Solution2 {
public:
    vector<TreeNode*> temp;
    void getPath(TreeNode *root, TreeNode *p, vector<TreeNode*> &path) {
    	if (root == p) {
            path = temp;
            return;
        }
        temp.push_back(root);
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
        while (i<pathp.size() && i<pathq.size()) {
            if (pathp[i] != pathq[i])
                break;
            i++;
        }
        return pathp[i - 1];
    }
};