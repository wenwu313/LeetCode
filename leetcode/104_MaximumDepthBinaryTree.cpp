#include<iostream>
#include<stack>
#include<queue>
#include<algorithm>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}	
};

//int maxDepth(TreeNode* root) {    //Recursive
//	if (!root) return 0;
//	return 1 + max(maxDepth(root->left), maxDepth(root->right));
//}

int maxDepth(TreeNode* root) {    //BFS
	if (!root) return 0;
	queue<TreeNode*> que;
	que.push(root);
	int count = 0;
	while (!que.empty()){
		int size = que.size();	
		while (size-- > 0){
			TreeNode *cur = que.front();
			que.pop();
			if (cur->left)
				que.push(cur->left);
			if (cur->right)
				que.push(cur->right);
		}
		count++;
	}
	return count;
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
	int a[] = { 2, 3, 3, 4, 5, 5, -1, 8 };
	//int a[] = { 1, 2, 2, 3, 4, 4, 3 };
	int size = sizeof(a) / sizeof(int);
	TreeNode* root = creatBTree(a, 0, size);
	cout << maxDepth(root) << endl;
	cin.get();
	return 0;
}
