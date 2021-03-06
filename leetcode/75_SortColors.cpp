class Solution {
public:
    void sortColors(vector<int>& nums) {
        int begin = -1, end = nums.size() - 1;
        for (int i = 0; i <= end; i++) {
            if (nums[i] == 0) {
                swap(nums[++begin], nums[i]);
            }
            if (nums[i] == 2) {
                swap(nums[i--], nums[end--]);
            }
        }
    }
};