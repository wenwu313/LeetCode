## 剑指offer部分源代码

### 5.从尾到头打印链表
```c++
void printFunc(ListNode* head, vector<int> &res){
	if (!head) return;
	printFunc(head->next, res);
	res.push_back(head->val);
}

vector<int> printListFromTailToHead(ListNode* head) {
	vector<int> res;
	printFunc(head, res);
	return res;
}
```
### 6.重建二叉树（前序和中序）

```c++
TreeNode* reConstructBinaryTree(vector<int> pre, vector<int> vin) {
    if (pre.empty() || vin.empty())
        return NULL;
    return reConstruct(pre, vin, 0, pre.size() - 1, 0, vin.size() - 1);
}

TreeNode* reConstruct(vector<int> &pre, vector<int> &vin, int pStart, int pEnd, int vStart, int vEnd) {
    if (vStart>vEnd)
        return NULL;
    TreeNode *root = new TreeNode(pre[pStart]);
    for (int i = vStart; i <= vEnd; i++) {
        if (pre[pStart] == vin[i]) {
            root->left = reConstruct(pre, vin, pStart + 1, pStart + i - vStart, vStart, i - 1);
            root->right = reConstruct(pre, vin, pEnd - vEnd + i + 1, pEnd, i + 1, vEnd);
            break;
        }
    }
    return root;
}
```
### 8.旋转数组的最小数字
```c++
int minNumberInRotateArray(vector<int> rotateArray) {
	int left = 0, right = rotateArray.size() - 1;
	while (left<right){
		int mid = (left + right) >> 1;
		if (rotateArray[mid]>rotateArray[right])
			left = mid + 1;
		else
			right = mid;
	}
	return rotateArray[left];
}
```
### 10.二进制中1的个数
```c++
int NumberOf1(int n) {
	int count = 0;
	while (n){
		n = n&(n - 1);
		count++;
	}
	return count;
}
```
### 11.数值的整数次方
```c++
double Power(double base, int exponent) {
	if (exponent == 0) return 1;
	if (exponent<0)
		return 1.0 / Power(base, -exponent);
	int temp = Power(base, exponent / 2);
	if (exponent & 0x01 == 1)
		return base*temp*temp;
	else
		return temp*temp;
}
```
### 15.链表中倒数第k个结点
```c++
ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
	if (!pListHead || k <= 0) return NULL;
	ListNode *p1 = pListHead, *p2 = pListHead;
	for (int i = 1; i<k; i++){
		if (p2->next)
			p2 = p2->next;
		else
			return NULL;
	}
	while (p2->next){
		p1 = p1->next;
		p2 = p2->next;
	}
	return p1;
}
```
### 16.反转链表
```c++
ListNode* ReverseList(ListNode* pHead) {
	ListNode *pre = NULL;
	while (pHead){
		ListNode* temp = pHead->next;
		pHead->next = pre;
		pre = pHead;
		pHead = temp;
	}
	return pre;
}
```
### 17.合并两个排序链表

```c++
ListNode* Merge(ListNode* pHead1, ListNode* pHead2) {
    if (!pHead1)
        return pHead2;
    if (!pHead2)
        return pHead1;

    if (pHead1->val<pHead2->val) {
        pHead1->next = Merge(pHead1->next, pHead2);
        return pHead1;
    }
    else {
        pHead2->next = Merge(pHead1, pHead2->next);
        return pHead2;
    }
}
```
### 18.树的子结构

```c++
bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
{
    if (!pRoot1 || !pRoot2) return false;
    return IsSubtree(pRoot1, pRoot2) || HasSubtree(pRoot1->left, pRoot2) || HasSubtree(pRoot1->right, pRoot2);
}

bool IsSubtree(TreeNode* pRoot1, TreeNode* pRoot2) {
    if (!pRoot2) return true;    //注意判断的顺序
    if (!pRoot1) return false;
    if (pRoot1->val != pRoot2->val) return false;
    return IsSubtree(pRoot1->left, pRoot2->left) && IsSubtree(pRoot1->right, pRoot2->right);
}
```
### 19.二叉树的镜像
```c++
void Mirror(TreeNode *pRoot) {
	if (!pRoot) return;
	swap(pRoot->left, pRoot->right);
	Mirror(pRoot->left);
	Mirror(pRoot->right);
}
```
### 20.顺时针打印矩阵

```c++
vector<int> spiralOrder(vector<vector<int>>& matrix) {
    vector<int> res;
    if (matrix.empty())
        return res;
    int m = matrix.size() - 1, n = matrix[0].size() - 1;
    for (int i = 0, j = 0; i <= m && j <= n; i++, j++) {

        for (int k = j; k <= n; k++)
            res.push_back(matrix[i][k]);

        for (int k = i + 1; k <= m; k++)
            res.push_back(matrix[k][n]);

        for (int k = n - 1; k >= j && i != m; k--)
            res.push_back(matrix[m][k]);

        for (int k = m - 1; k>i && j != n; k--)
            res.push_back(matrix[k][j]);

        m--;
        n--;
    }
    return res;
}
```
### 21.包含min函数的栈

```c++
class MinStack {
public:
    int min = INT_MAX;
    stack<int> stack1;

    MinStack() {

    }

    void push(int x) {
        if (x <= min) {
            stack1.push(min);
            min = x;
        }
        stack1.push(x);
    }

    void pop() {
        if (stack1.top() == min) {
            stack1.pop();
            min = stack1.top();
        }
        stack1.pop();
    }

    int top() {
        return stack1.top();
    }

    int getMin() {
        return min;
    }
};
```
### 22.栈的输入输出队列

```c++
bool IsPopOrder(vector<int> pushV, vector<int> popV) {
    stack<int> stk;
    int j = 0;
    for (int i = 0; i < pushV.size(); i++) {
        stk.push(pushV[i]);
        while (j < popV.size() && stk.top() == popV[j]) {
            stk.pop();
            j++;
        }
    }
    return stk.empty();
}
```
### 23.从上往下打印二叉树
```c++
vector<int> PrintFromTopToBottom(TreeNode* root) {
	vector<int> res;
	if (!root) return res;
	queue<TreeNode*> que;
	que.push(root);
	while (!que.empty()){
		int size = que.size();
		while (size-->0){
			TreeNode *temp = que.front();
			res.push_back(temp->val);
			que.pop();
			if (temp->left)
				que.push(temp->left);
			if (temp->right)
				que.push(temp->right);
		}
	}
	return res;
}
```
### 24.二叉搜索树的后序遍历序列(判断）
```c++
bool judge(vector<int> seq, int left, int right){
	if (left<right){
		int i = right - 1;
		while (i >= left && seq[i]>seq[right]) i--;
		int mid = i;
		while (i >= left){
			if (seq[i]>seq[right]) return false;
			i--;
		}
		return judge(seq, left, mid) && judge(seq, mid + 1, right - 1);
	}
	return true;
}

bool VerifySquenceOfBST(vector<int> sequence) {
	if (sequence.empty()) return false;
	return judge(sequence, 0, sequence.size() - 1);
}
```
### 25.二叉树中和为某一值的路径
```c++
void findfunc(TreeNode* root, int sum, vector<int> &path, vector<vector<int>> &res){
	sum -= root->val;
	path.push_back(root->val);
	if (sum == 0 && !root->left && !root->right)
		res.push_back(path);
	if (root->left)
		findfunc(root->left, sum, path, res);
	if (root->right)
		findfunc(root->right, sum, path, res);
	path.pop_back();
}

vector<vector<int>> FindPath(TreeNode* root, int expectNumber) {
	vector<vector<int>> res;
	vector<int> path;
	if (!root) return res;
	findfunc(root, expectNumber, path, res);
	return res;
}
```
### 27.二叉树转双向链表

```c++
TreeNode* Convert(TreeNode* pRootOfTree){
    if (pRootOfTree == NULL) return NULL;
    pRootOfTree = ConvertNode(pRootOfTree);
    while (pRootOfTree->left) pRootOfTree = pRootOfTree->left;
    return pRootOfTree;
}

TreeNode* ConvertNode(TreeNode* root) {
    if (root->left) {
        TreeNode* left = ConvertNode(root->left);
        while (left->right) left = left->right;
        left->right = root;
        root->left = left;
    }
    if (root->right) {
        TreeNode* right = ConvertNode(root->right);
        while (right->left) right = right->left;
        right->left = root;
        root->right = right;
    }
    return root;
} 
```
### 28.字符串的排列
```c++
void permuteFunc(string str, int begin, vector<string> &res){
	if (begin == str.size() - 1){
		res.push_back(str);
		return;
	}
	for (int i = begin; i<str.size(); i++){
		if (i != begin && str[i] == str[i - 1])
			continue;
		swap(str[i], str[begin]);
		permuteFunc(str, begin + 1, res);
	}
}

vector<string> Permutation(string str) {
	vector<string> res;
	if (str.empty()) return res;
	sort(str.begin(), str.end());
	permuteFunc(str, 0, res);
	return res;
}
```
### 29.数组中出现次数超过一半的数字
```c++
int majorityElement(vector<int>& nums) {
    int x = nums[0], count = 1;
    for (int i = 1; i < nums.size(); i++) {
        if (count == 0) {
            x = nums[i];
            count = 1;
            continue;
        }
        if (nums[i] == x)  count++;
        else  count--;
    }
    return x;
}
```
### 30.最小的k个数
```c++
int partition(vector<int> &nums, int begin, int end){
	int i = begin - 1;
	for (int j = begin; j<end; j++){
		if (nums[j]<nums[end])
			swap(nums[++i], nums[j]);
	}
	swap(nums[++i], nums[end]);
	return i;
}

vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
	vector<int> res;
	if (input.empty() || k>input.size()) return res;
	int left = 0, right = input.size() - 1;
	int pos = 0;
	while (left <= right){
		pos = partition(input, left, right);
		if (pos == k - 1) break;
		else if (pos >k - 1) right = pos - 1;
		else left = pos + 1;
	}
	for (int i = 0; i<k; i++)
		res.push_back(input[i]);
	return res;
}
```
### 31.连续子数组的最大和
```c++
int FindGreatestSumOfSubArray(vector<int> array) {
	int maxSum = array[0], pre = array[0];
	for (int i = 1; i<array.size(); i++){
		if (pre >= 0)
			pre = array[i] + pre;
		else
			pre = array[i];
		maxSum = max(maxSum, pre);
	}
	return maxSum;
}
```
### 32.1到n整数中1出现的次数

```c++
int NumberOf1Between1AndN_Solution(int n)
{
    int count = 0, loc = 1;
    int high = 0, cur = 0, low = 0;
    while (n / loc) {
        low = n - (n / loc)*loc;
        cur = (n / loc) % 10;
        high = n / (loc * 10);
        if (cur == 0)
            count += high*loc;
        else if (cur == 1)
            count += high*loc + low + 1;
        else
            count += (high + 1)*loc;
        loc = loc * 10;
    }
    return count;
}
```
### 35.第一个只出现一次的字符
```c++
int FirstNotRepeatingChar(string str) {
	map<char, int> mp;
	for (int i = 0; i < str.size(); ++i)
		mp[str[i]]++;
	for (int i = 0; i < str.size(); ++i){
		if (mp[str[i]] == 1)
			return i;
	}
	return -1;
}
```
### 36.数组中逆序对

```c++
int result;
void merge(vector<int> &nums, int left, int right, int mid) {
    vector<int> temp(right - left + 1, 0);
    int lstart = left, rstart = mid + 1;
    int tempIndex = 0;
    while (lstart <= mid && rstart <= right) {
        if (nums[lstart] <= nums[rstart])
            temp[tempIndex++] = nums[rstart++];
        else {
            temp[tempIndex++] = nums[lstart++];
            result += right - rstart + 1;
        }
    }
    while (lstart <= mid)  temp[tempIndex++] = nums[lstart++];
    while (rstart <= right)  temp[tempIndex++] = nums[rstart++];
    for (int i = left; i <= right; i++) {
        nums[i] = temp[i - left];
    }
}

void mergeSort(vector<int> &nums, int left, int right) {
    if (left < right) {
        int mid = (left + right) >> 1;
        mergeSort(nums, left, mid);
        mergeSort(nums, mid + 1, right);
        merge(nums, left, right, mid);
    }
}
```
### 37.两个链表的第一个公共结点
```c++
ListNode* FindFirstCommonNode(ListNode* pHead1, ListNode* pHead2) {
	ListNode *cur1 = pHead1, *cur2 = pHead2;
	while (cur1 != cur2){
		cur1 = cur1 ? cur1->next : pHead2;
		cur2 = cur2 ? cur2->next : pHead1;
	}
	return cur1;
}
```
### 39.二叉树的深度
```c++
int TreeDepth(TreeNode* pRoot){
	if (!pRoot) return 0;
	return 1 + max(TreeDepth(pRoot->left), TreeDepth(pRoot->right));
}
```
### 39.平衡二叉树判断

```c++
bool IsBalanced(TreeNode* pRoot, int &depth) {
    if (!pRoot) {
        depth = -1;
        return true;
    }
    int left, right;
    if (IsBalanced(pRoot->left, left) && IsBalanced(pRoot->right, right)) {
        int diff = left - right;
        if (diff <= 1 && diff >= -1) {
            depth = 1 + (left>right ? left : right);
            return true;
        }
    }
    return false;
}

bool IsBalanced_Solution(TreeNode* pRoot) {
    int depth;
    return IsBalanced(pRoot, depth);
}
```
### 42.翻转单词顺序

```c++
string ReverseSentence(string str) {
    int len = str.size();
    int start = 0;
    for (int i = 0; i < len; i++)
    {
        if (str[i] == ' ')
        {
            reverse(str.begin() + start, str.begin() + i);
            start = i + 1;
        }
        if (i == len - 1)
        {
            reverse(str.begin() + start, str.end());
        }
    }
    reverse(str.begin(), str.end());
    return str;
}
```
### 47.不用加减乘除做加法

```c++
int Add(int num1, int num2){
	if (!num2) return num1;
	return Add(num1^num2, (num1&num2) << 1);
}
```
### 49.把字符串转化成整数

```c++
bool isTrue = false;
long long  myAtoi(string str) {
    int i = 0, minus = 1;
    long long result = 0;
    if (str.empty())
        return result;
    while (i < str.size()) {
        if (str[i] == ' ') {
            i++;
            continue;
        }
        if (str[i] == '-') {
            minus = -1;
            i++;
        }
        else if (str[i] == '+')
            i++;
        break;
    }
    while (i < str.size()) {
        if (str[i] >= '0' && str[i] <= '9') {
            result = result * 10 + minus*(str[i] - '0');
            if (minus == 1 && result >INT_MAX || minus == -1 && result < INT_MIN)
                result = minus == 1 ? INT_MAX : INT_MIN;
            i++;
        }
        else
            break;
    }
    if (i == str.size())
        isTrue = true;
    return result;
}
```
### 50.二叉树最小公共祖先

```c++
bool getPath(TreeNode* root, TreeNode* node, vector<TreeNode*> &path) {
    if (root == node) {
        path.push_back(root);
        return true;
    }
    path.push_back(root);
    if (root->left && getPath(root->left, node, path) ||
        root->right && getPath(root->right, node, path))
        return true;
    path.pop_back();
    return false;
}

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (!root || !p || !q) return NULL;
    vector<TreeNode*> path1;
    vector<TreeNode*> path2;
    getPath(root, p, path1);
    getPath(root, q, path2);

    TreeNode *plast = NULL;
    for (int i = 0; i<path1.size() && i <path2.size(); i++) {
        if (path1[i] == path2[i])
            plast = path1[i];
        else
            break;
    }
    return plast;
}
```
### 51.数组中重复的数

```c++
bool duplicate(int numbers[], int length, int* duplication) {
    if (numbers == NULL || length <= 0)
        return false;
    for (int i = 0; i<length; i++) {
        if (numbers[i]<0 || numbers[i]>length - 1)
            return false;
    }
    for (int i = 0; i<length; i++) {
        while (i != numbers[i]) {
            if (numbers[i] == numbers[numbers[i]]) {
                *duplication = numbers[i];
                return true;
            }
            swap(numbers[i], numbers[numbers[i]]);
        }
    }
    return false;
}
```
### 56.链表中环的入口结点
```c++
ListNode* EntryNodeOfLoop(ListNode* pHead){
	if (!pHead) return NULL;
	ListNode *pfast = pHead, *pslow = pHead;
	while (pfast && pfast->next){
		pfast = pfast->next->next;
		pslow = pslow->next;
		if (pfast == pslow){
			pslow = pHead;
			while (pslow != pfast){
				pslow = pslow->next;
				pfast = pfast->next;
			}
			return pslow;
		}
	}
	return NULL;
}
```
### 57.删除链表中重复的结点
```c++
ListNode* deleteDuplication(ListNode* pHead){
	if (!pHead) return NULL;
	ListNode *prehead = new ListNode(-1), *cur = prehead;
	prehead->next = pHead;
	while (cur->next && cur->next->next){
		if (cur->next->val == cur->next->next->val){
			int temp = cur->next->val;
			while (cur->next && cur->next->val == temp){
				cur->next = cur->next->next;
			}
		}
		else
			cur = cur->next;
	}
	return prehead->next;
}
```
### 59.对称的二叉树
```c++
bool SymmetircFunc(TreeNode* node1, TreeNode *node2){
	if (!node1 && !node2) return true;
	if (!node1 || !node2) return false;
	if (node1->val != node2->val) return false;
	return SymmetircFunc(node1->right, node2->left) && SymmetircFunc(node1->left, node2->right);
}

bool isSymmetrical(TreeNode* pRoot){
	if (!pRoot) return true;
	return SymmetircFunc(pRoot->left, pRoot->right);
}
```
### 64.数据流中的中位数

```c++
class Solution {
public:
    void Insert(int num)
    {
        count++;
        if (count & 0x1 == 1) {
            minheap.push(num);
            maxheap.push(minheap.top());
            minheap.pop();
        }
        else {
            maxheap.push(num);
            minheap.push(maxheap.top());
            maxheap.pop();
        }
    }

    double GetMedian()
    {
        if (count & 0x1 == 1)
            return maxheap.top();
        else
            return (maxheap.top() + minheap.top()) / 2.0;  //注意浮点数
    }
private:
    int count = 0;
    priority_queue<int> maxheap;
    priority_queue<int, vector<int>, greater<int>> minheap;
};
```