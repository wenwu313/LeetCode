class Solution {
public:
    //recursive
    void preorderTraversal(TreeNode* root, vector<int> &res)
    {
        if (root == NULL) return;
        res.push_back(root->val);
        preorderTraversal(root->left, res);
        preorderTraversal(root->right, res);
    }

    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        preorderTraversal(root, res);
        return res;
    }
};

/* iter1
vector<int> preorderTraversal(TreeNode* root) {    
    vector<int> res;  
    stack<TreeNode*> toVisit;  
    while (root || !toVisit.empty()){  
        if (root){  
            res.push_back(root->val);  
            toVisit.push(root);  
            root = root->left;  
        }  
        else{  
            root = toVisit.top();  
            toVisit.pop();  
            root = root->right;  
        }  
    }  
    return res;  
}  
*/

/*iter2
vector<int> preorderTraversal1(TreeNode *root) {  
    stack<TreeNode*> toVisit;  
    vector<int> res;  
    if (root == NULL)  
        return res;  
    toVisit.push(root);  
    while (!toVisit.empty())  
    {  
        TreeNode* node = toVisit.top();  
        toVisit.pop();  
        res.push_back(node->val);          
        if (node->right)  
            toVisit.push(node->right);  
        if (node->left)  
            toVisit.push(node->left);  
    }  
    return res;  
}  
*/