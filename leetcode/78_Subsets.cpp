class Solution {
public:
    void subsets(vector<int> &nums, vector<vector<int>> &result, vector<int> rows, int begin) {
        result.push_back(rows);
        for (int i = begin; i < nums.size(); i++) {
            rows.push_back(nums[i]);
            subsets(nums, result, rows, i + 1);
            rows.pop_back();
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> rows;
        subsets(nums, result, rows, 0);
        return result;
    }
};