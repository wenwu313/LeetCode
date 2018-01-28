#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
	vector<vector<int>> result;
	queue<TreeNode*> que;
	if (!root) return result;
	que.push(root);
	bool isTrue = false;
	while (!que.empty()){
		int size = que.size();
		vector<int> row;
		while (size-- > 0){
			TreeNode *temp = que.front();
			que.pop();
			row.push_back(temp->val);
			if (temp->left)
				que.push(temp->left);
			if (temp->right)
				que.push(temp->right);
		}
		if (isTrue)
			reverse(row.begin(), row.end());
		isTrue = !isTrue;
		result.push_back(row);
	}
	return result;
}

vector<vector<int> > zigzagLevelOrder(TreeNode* root) {
	vector<vector<int> > result;
	queue<TreeNode*> nodesQueue;
	if (!root) return result;
	nodesQueue.push(root);
	bool leftToRight = true;
	while (!nodesQueue.empty()) {
		int size = nodesQueue.size();
		vector<int> row(size);
		for (int i = 0; i < size; i++) {
			TreeNode* node = nodesQueue.front();
			nodesQueue.pop();
			int index = (leftToRight) ? i : (size - 1 - i);
			row[index] = node->val;
			if (node->left) {
				nodesQueue.push(node->left);
			}
			if (node->right) {
				nodesQueue.push(node->right);
			}
		}
		leftToRight = !leftToRight;
		result.push_back(row);
	}
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
	int a[] = { 2, 3, 3, 4, 5, 5, -1, 8 };
	int size = sizeof(a) / sizeof(int);
	TreeNode* root = creatBTree(a, 0, size);
	vector<vector<int>> ans = zigzagLevelOrder(root);
	for (int i = 0; i < ans.size(); i++){
		for (int j = 0; j < ans[i].size(); j++){
			cout << ans[i][j] << ' ';
		}
		cout << endl;
	}
	cin.get();
	return 0;
}