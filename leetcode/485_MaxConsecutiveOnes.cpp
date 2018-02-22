
int findMaxConsecutiveOnes(vector<int>& nums) {
    int result = 0;
    int temp = 0;
    for (int i = 0; i<nums.size(); i++) {
        if (nums[i] == 1)
            temp++;
        if (nums[i] == 0 || i == nums.size() - 1)
        {
            if (temp>result)
                result = temp;
            temp = 0;
        }
    }
    return result;
}