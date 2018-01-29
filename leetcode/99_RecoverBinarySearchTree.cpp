class Solution {  
public:  
    TreeNode *pre=NULL;  
    TreeNode *mistake1=NULL;  
    TreeNode *mistake2=NULL;  
     
    void inordertraveral(TreeNode* root){  
        if(!root) return;  
        inordertraveral(root->left);  
        if(pre && root->val<pre->val){  
            if(!mistake1){  
                mistake1=pre;  
                mistake2=root;  
            }  
            else mistake2=root;  
        }  
        pre=root;  
        inordertraveral(root->right);  
    }  
      
    void recoverTree(TreeNode* root) {  
        inordertraveral(root);  
        swap(mistake1->val,mistake2->val);  
    }  
}; 