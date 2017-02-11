#include<iostream>
#include<vector>
#include<stack>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}	
};

//void inorderTraversal(TreeNode* root,vector<int> &res)   //递归写法
//{   
//	if (root == NULL) return;
//	inorderTraversal(root->left, res);
//	res.push_back(root->val);
//	inorderTraversal(root->right, res);
//}
//
//vector<int> inorderTraversal(TreeNode* root) {  
//	vector<int> res;
//	inorderTraversal(root,res);
//	return res;
//}

vector<int> inorderTraversal(TreeNode* root) {
	vector<int> nodes;
	stack<TreeNode*> toVisit;
	TreeNode* curNode = root;
	while (curNode || !toVisit.empty()) {
		if (curNode) {
			toVisit.push(curNode);
			curNode = curNode->left;
		}
		else {
			curNode = toVisit.top();
			toVisit.pop();
			nodes.push_back(curNode->val);
			curNode = curNode->right;
		}
	}
	return nodes;
}



TreeNode* creatBTree(int data[], int index, int n)
{
	TreeNode *pNode = NULL;
	if (index < n)  //数组中-1 表示该节点为空
	{
		pNode = new TreeNode(data[index]);
		pNode->left = creatBTree(data, 2 * index + 1, n);  //将二叉树按照层序遍历, 依次标序号, 从0开始
		pNode->right = creatBTree(data, 2 * index + 2, n);
	}
	return pNode;
}

void Print(TreeNode* p)  //前序遍历
{
	if (NULL == p)
		return;
	cout << p->val << endl;
	Print(p->left);
	Print(p->right);
}

int main()
{
	int a[] = { 0, 1, 2, 3, 4, 5, 6 };
	int size = sizeof(a) / sizeof(int);
	TreeNode* tree = creatBTree(a, 0, size);
	//Print(tree);
	vector<int> trav = inorderTraversal(tree);
	for (int i = 0; i < trav.size(); i++)
		cout << trav[i] << ' ';
	cout << endl;
	cin.get();
	return 0;
}
