class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        if (heights.empty())
            return 0;
        stack<int> stk;
        stk.push(heights[0]);
        int result = 0;
        for (int i = 1; i<heights.size(); i++) {
            if (heights[i] >= stk.top())
                stk.push(heights[i]);
            else {
                int len = 0;
                while (!stk.empty() && heights[i]<stk.top()) {
                    len++;
                    int temp = stk.top()*len;
                    if (temp>result)
                        result = temp;
                    stk.pop();
                }
                for (int j = 0; j <= len; j++)
                    stk.push(heights[i]);
            }
        }
        for (int i = 0; i<heights.size(); i++) {
            int temp = stk.top()*(i + 1);
            if (temp>result)
                result = temp;
            stk.pop();
        }
        return result;
    }
};