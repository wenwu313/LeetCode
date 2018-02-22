class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int lastBit = 0, num1 = 0, num2 = 0;
        for (int num : nums)
            lastBit ^= num;
        lastBit = (lastBit&(lastBit - 1)) ^ lastBit;
        for (int num : nums) {
            if (num & lastBit)
                num1 ^= num;
            else
                num2 ^= num;
        }
        return vector<int>{num1, num2};
    }
};