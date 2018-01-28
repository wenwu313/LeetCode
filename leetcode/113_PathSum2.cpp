#include<iostream>
#include<vector>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void pathSum(TreeNode* root, int sum, vector<int> &path, vector<vector<int>> &res)
{
	path.push_back(root->val);
	sum -= root->val;
	if (sum == 0 && !root->left && !root->right)
		res.push_back(path);
	if (root->left)
		pathSum(root->left, sum, path, res);
	if (root->right)
		pathSum(root->right, sum, path, res);
	path.pop_back();
}

vector<vector<int>> pathSum(TreeNode* root, int sum) {
	vector<vector<int>> ans;
	if (!root) return ans;
	vector<int> path;
	pathSum(root, sum, path, ans);
	return ans;
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

int main()
{
	int a[] = { 5, 4, 8, 11, -1, 13, 4, 7, 2, -1, -1, -1, -1, 5, 1 };
	int size = sizeof(a) / sizeof(int);
	TreeNode* root = creatBTree(a, 0, size);
	vector<vector<int>> ans = pathSum(root, 22);
	for (int i = 0; i < ans.size(); i++){
		for (int j = 0; j < ans[i].size(); j++){
			cout << ans[i][j] << ' ';
		}
		cout << endl;
	}
	cin.get();
	return 0;
}
