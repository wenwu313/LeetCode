class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int res = nums.size();
        for (int i = 0; i < nums.size(); i++) {
            res ^= i;
            res ^= nums[i];
        }
        return res;
    }

    int missingNumber1(vector<int>& nums) {  //二分
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int left = 0, right = n, mid = 0;
        while (left<right) {
            mid = (left + right) >> 1;
            if (nums[mid]>mid)
                right = mid;
            else
                left = mid + 1;
        }
        return left;
    }

    int missingNumber2(vector<int>& nums) {  //变换，用索引标注
        int n = nums.size();
        for (int i = 0; i<n; i++) {
            while (nums[i] >= 0 && nums[i]<n && nums[i] != i)
                swap(nums[i], nums[nums[i]]);
        }
        for (int i = 0; i<n; i++) {
            if (i != nums[i])
                return i;
        }
        return n;
    }
};