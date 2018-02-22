class Solution {
public:
    int trap(vector<int>& height) {
        if (height.empty())
            return 0;
        int i = 0, j = height.size() - 1;
        int leftHeight = height[i], rightHeight = height[j];
        int result = 0;
        while (i<j) {
            if (height[i] <= height[j]) {
                if (height[i]>leftHeight)
                    leftHeight = height[i];
                else
                    result += leftHeight - height[i];
                i++;
            }
            else {
                if (height[j]>rightHeight)
                    rightHeight = height[j];
                else
                    result += rightHeight - height[j];
                j--;
            }
        }
        return result;
    }
};