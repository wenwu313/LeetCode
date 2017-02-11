class BSTIterator {
	stack<TreeNode *> myStack;
public:
	BSTIterator(TreeNode *root) {
		pushNode(root);
	}

	/** @return whether we have a next smallest number */
	bool hasNext() {
		return !myStack.empty();
	}

	/** @return the next smallest number */
	int next() {
		TreeNode *tmpNode = myStack.top();
		myStack.pop();
		pushNode(tmpNode->right);
		return tmpNode->val;
	}

private:
	void pushNode(TreeNode *node) {
		while (node){
			myStack.push(node);
			node = node->left;
		}
	}
};
