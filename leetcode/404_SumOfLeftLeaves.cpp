#include<iostream>
#include<stack>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int sumOfLeftLeaves(TreeNode* root, bool isleft) {
    if (!root) return 0;
    if (!root->left && !root->right) {
        return isleft ? root->val : 0;
    }
    return sumOfLeftLeaves(root->left, true) + sumOfLeftLeaves(root->right, false);
}

int sumOfLeftLeaves(TreeNode* root) {
    if (!root)  return 0;
    return sumOfLeftLeaves(root, false);
}

int sumOfLeftLeaves(TreeNode* root) {
    if (!root)  return 0;
    int result = 0;
    if (root->left) {
        if (!root->left->left && !root->left->right)
            result += root->left->val;
        else
            result += sumOfLeftLeaves(root->left);
    }
    result += sumOfLeftLeaves(root->right);
    return result;
}

TreeNode* creatBTree(int data[], int index, int n)
{
    TreeNode *pNode = NULL;
    if (index < n && data[index] != -1)  //-1令树结点为NULL
    {
        pNode = new TreeNode(data[index]);
        pNode->left = creatBTree(data, 2 * index + 1, n);  //将二叉树按照层序遍历, 依次标序号, 从0开始
        pNode->right = creatBTree(data, 2 * index + 2, n);
    }
    return pNode;
}

int main()
{
    int a[] = { 1, 2, 3, 4, 5, 6, 7 };
    int size = sizeof(a) / sizeof(int);
    TreeNode* root = creatBTree(a, 0, size);
    cout << sumOfLeftLeaves(root) << endl;
    cin.get();
    return 0;
}