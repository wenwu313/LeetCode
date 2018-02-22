class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        if (!root)
            return result;
        stack<TreeNode*> stk;
        stk.push(root);
        while (!stk.empty()){
            TreeNode *node = stk.top();
            stk.pop();
            result.push_back(node->val);
            if (node->left)
                stk.push(node->left);
            if (node->right)
                stk.push(node->right);
        }
        reverse(result.begin(), result.end());
        return result;
    }
};

/* recursive
void postorderTraversal(TreeNode* root,vector<int> &res)    
{     
    if (root == NULL) return;     
    postorderTraversal(root->left, res);                            
    postorderTraversal(root->right, res);  
    res.push_back(root->val);  
}  
  
vector<int> postorderTraversal(TreeNode* root) {    
    vector<int> res;  
    postorderTraversal(root,res);  
    return res;  
}  
*/

