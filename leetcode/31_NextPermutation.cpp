class Solution {
public:
    void nextPermutation(vector<int>& nums) { //找到第一个升序对
        int i = nums.size() - 1;
        while (i>0) {
            if (nums[i] > nums[i - 1])
                break;
            i--;
        }
        if (i == 0) {
            reverse(nums.begin(), nums.end());
            return;
        }
        for (int k = nums.size() - 1; k >= i; k--) {
            if (nums[k] > nums[i - 1]) {
                swap(nums[k], nums[i - 1]);
                break;
            }
        }
        reverse(nums.begin() + i, nums.end());
    }
};
