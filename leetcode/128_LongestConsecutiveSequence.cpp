/*
如果使用排序，复杂度不满足要求。所以以空间换时间，用unordered_set保存数据，每次选取一个数，看相邻的数是否在set里。
这里由于连续的几个数求出的结果是一致的，因此求长度时将遍历到的数从set里擦除，同时循环开始时要判断该数是否在set中。
*/
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> values(nums.begin(), nums.end());
        int max_len = 0;
        for (int num : nums) {
            if (values.find(num) == values.end()) continue;
            int len = 1;
            for (int i = num - 1; values.find(i) != values.end(); i--) {
                values.erase(i);
                len++;
            }
            for (int i = num + 1; values.find(i) != values.end(); i++) {
                values.erase(i);
                len++;
            }
            max_len = max(max_len, len);
        }
        return max_len;
    }
};