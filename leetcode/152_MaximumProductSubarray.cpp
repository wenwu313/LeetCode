class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int max0 = nums[0], min0 = nums[0];
        int pro = nums[0];
        for (int i = 1; i<nums.size(); i++) {
            int temp1 = nums[i] * max0, temp2 = nums[i] * min0;
            max0 = max(max(temp1, temp2), nums[i]);
            min0 = min(min(temp1, temp2), nums[i]);
            pro = max(pro, max0);
        }
        return pro;
    }
};