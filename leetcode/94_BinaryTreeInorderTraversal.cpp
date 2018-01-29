class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> toVisit;
        while (root || !toVisit.empty()) {
            if (root) {
                toVisit.push(root);
                root = root->left;
            }
            else {
                root = toVisit.top();
                toVisit.pop();
                res.push_back(root->val);
                root = root->right;
            }
        }
        return res;
    }
};

//void inorderTraversal(TreeNode* root, vector<int> &res)  //iter
//{
//  if (root == NULL) return;
//  inorderTraversal(root->left, res);
//  res.push_back(root->val);
//  inorderTraversal(root->right, res);
//}
//
//vector<int> inorderTraversal(TreeNode* root) {
//  vector<int> res;
//  inorderTraversal(root, res);
//  return res;
//}