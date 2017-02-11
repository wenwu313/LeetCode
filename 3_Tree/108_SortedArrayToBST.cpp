#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* sortedArrayToBST(vector<int>& nums,int begin,int end)
{
	TreeNode *root = NULL;
	if(begin <= end){
		int mid = (begin + end) >> 1;
		root = new TreeNode(nums[mid]);
		root->left = sortedArrayToBST(nums, begin, mid - 1);
		root->right = sortedArrayToBST(nums, mid + 1, end);
	}
	return root;
}

TreeNode* sortedArrayToBST(vector<int>& nums) {
	TreeNode *root = sortedArrayToBST(nums, 0, nums.size() - 1);
	return root;
}

TreeNode* creatBTree(int data[], int index, int n)
{
	TreeNode *pNode = NULL;
	if (index < n && data[index]!=-1)  //-1令树结点为NULL
	{
		pNode = new TreeNode(data[index]);
		pNode->left = creatBTree(data, 2 * index + 1, n);  //将二叉树按照层序遍历, 依次标序号, 从0开始
		pNode->right = creatBTree(data, 2 * index + 2, n);
	}
	return pNode;
}

void inorderTraversal(TreeNode* root, vector<int> &res)
{
	if (root == NULL) return;
	inorderTraversal(root->left, res);
	res.push_back(root->val);
	inorderTraversal(root->right, res);
}

vector<int> inorderTraversal(TreeNode* root) {
	vector<int> res;
	inorderTraversal(root, res);
	return res;
}

int main()
{
	/*int a[] = { 2, 3, 3, 4, 5, 5, -1, 8 };  
	int size = sizeof(a) / sizeof(int);*/
	vector<int> a = { 1, 2, 3, 4, 5, 6, 7 };
	TreeNode *root = sortedArrayToBST(a);
	vector<int> ans = inorderTraversal(root);
	for (int i = 0; i < ans.size(); i++)
		cout << ans[i] << ' ';
	cout << endl;
	//TreeNode* root = creatBTree(a, 0, size);
	cin.get();
	return 0;
}
