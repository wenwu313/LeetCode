## 剑指offer部分源代码

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
### 27.二叉树转双向链表

```c++
TreeNode* Convert(TreeNode* pRootOfTree)
{
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
void getPath(TreeNode *root, TreeNode * node, vector<TreeNode*> &path, vector<TreeNode*> &temp) {
    if (path.size() > 0)
        return;
    temp.push_back(root);
    if (root == node) {
        path = temp;
        return;
    }
    if (root->left)
        getPath(root->left, node, path, temp);
    if (root->right)
        getPath(root->right, node, path, temp);
    temp.pop_back();
}

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (!root || !p || !q) return NULL;
    vector<TreeNode*> pathp, pathq, temp;
    getPath(root, p, pathp, temp);
    temp.clear();    //清空数组
    getPath(root, q, pathq, temp);
    TreeNode *plast = NULL;
    for (int i = 0; i < pathp.size() && i < pathq.size(); i++) {
        if (pathp[i] == pathq[i])
            plast = pathp[i];
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