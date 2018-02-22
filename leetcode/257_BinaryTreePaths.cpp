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

void binaryTreePaths(TreeNode* root, vector<string> &result, string path) {
    if (root->left == NULL && root->right == NULL) {
        result.push_back(path);
        return;            //可要可不要
    }
    if (root->left)
        binaryTreePaths(root->left, result, path + "->" + to_string(root->left->val));
    if (root->right)
        binaryTreePaths(root->right, result, path + "->" + to_string(root->right->val));
}

vector<string> binaryTreePaths(TreeNode* root) {
    vector<string> result;
    if (!root) return result;
    binaryTreePaths(root, result, to_string(root->val));
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
    int a[] = { 37, -34, -48, -1, -100, -100, 48, -1, -1, -1, -1, -54, -1, -71, -22, -1, -1, -1, 8 };
    int size = sizeof(a) / sizeof(int);
    TreeNode* root = creatBTree(a, 0, size);
    vector<string> ans = binaryTreePaths(root);
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << endl;
    }
    cin.get();
    return 0;
}