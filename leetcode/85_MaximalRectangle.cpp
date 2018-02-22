class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        if (heights.empty()) return 0;
        int result = 0;
        stack<int> stk;
        stk.push(heights[0]);
        for (int i = 1; i < heights.size(); i++) {
            if (heights[i] >= stk.top()) {
                stk.push(heights[i]);
            }
            else {
                int len = 0;
                while (!stk.empty() && stk.top()>heights[i]) {
                    len++;
                    int temp = stk.top()*len;
                    if (temp > result)
                        result = temp;
                    stk.pop();
                }
                for (int j = 0; j <= len; j++)
                    stk.push(heights[i]);
            }
        }
        for (int i = 0; i < heights.size(); i++) {
            int temp = stk.top()*(i + 1);
            if (temp>result)
                result = temp;
            stk.pop();
        }
        return result;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty()) return 0;
        int m = matrix.size(), n = matrix[0].size();
        int result = 0;
        vector<int> height(n, 0);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                height[j] = matrix[i][j] == '1' ? height[j] + 1 : 0;
            }
            result = max(result, largestRectangleArea(height));
        }
        return result;
    }
};