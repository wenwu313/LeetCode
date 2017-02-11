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

void postorderTraversal(TreeNode* root,vector<int> &res)  
{   
	if (root == NULL) return;	
	postorderTraversal(root->left, res);                          
	postorderTraversal(root->right, res);
	res.push_back(root->val);
}

vector<int> postorderTraversal(TreeNode* root) {  
	vector<int> res;
	postorderTraversal(root,res);
	return res;
}

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

vector<int> inorderTraversal(TreeNode* root) {
	vector<int> res;
	stack<TreeNode*> toVisit;
	while (root || !toVisit.empty()) {
		if (root) {
			toVisit.push(root);
			root = root->left;
		}
		else {
			root = toVisit.top();
			toVisit.pop();
			res.push_back(root->val);
			root = root->right;
		}
	}
	return res;
}

vector<int> postorderTraversal(TreeNode *root) {
	stack<TreeNode*> toVisit;
	vector<int> res;
	if (root == NULL)
		return res;
	toVisit.push(root);
	while (!toVisit.empty())
	{
		TreeNode* node = toVisit.top();
		res.push_back(node->val);
		toVisit.pop();
		if (node->left)
			toVisit.push(node->left);
		if (node->right)
			toVisit.push(node->right);
	}
	reverse(res.begin(), res.end());
	return res;
}

TreeNode* creatBTree(int data[], int index, int n)
{
	TreeNode *pNode = NULL;
	if (index < n)  
	{
		pNode = new TreeNode(data[index]);
		pNode->left = creatBTree(data, 2 * index + 1, n);  //将二叉树按照层序遍历, 依次标序号, 从0开始
		pNode->right = creatBTree(data, 2 * index + 2, n);
	}
	return pNode;
}


int main()
{
	int a[] = { 0, 1, 2, 3, 4, 5, 6 };
	int size = sizeof(a) / sizeof(int);
	TreeNode* tree = creatBTree(a, 0, size);
	vector<int> trav = postorderTraversal(tree);
	for (int i = 0; i < trav.size(); i++)
		cout << trav[i] << ' ';
	cout << endl;
	cin.get();
	return 0;
}
