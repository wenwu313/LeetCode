#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<int> rightSideView(TreeNode* root) {
	vector<int> result;
	if (!root)
		return result;
	queue<TreeNode*> que;	
	que.push(root);
	while (!que.empty()){
		result.push_back(que.back()->val);
		int size = que.size();
		while (size-- > 0){
			TreeNode *temp = que.front();
			que.pop();
			if (temp->left)
				que.push(temp->left);
			if (temp->right)
				que.push(temp->right);
		}
	}
	return result;
}

TreeNode* creatBTree(int data[], int index, int n)
{
	TreeNode *pNode = NULL;
	if (index < n && data[index]!=-1)  
	{
		pNode = new TreeNode(data[index]);
		pNode->left = creatBTree(data, 2 * index + 1, n);  
		pNode->right = creatBTree(data, 2 * index + 2, n);
	}
	return pNode;
}

int main()
{
	int a[] = { 1, 2, 3, -1, 5, -1, 4 };
	int size = sizeof(a) / sizeof(int);
	TreeNode* root = creatBTree(a, 0, size);
	vector<int> ans = rightSideView(root);
	for (int i = 0; i < ans.size(); i++)
		cout << ans[i] << ' ';
	cout << endl;
	cin.get();
	return 0;
}
