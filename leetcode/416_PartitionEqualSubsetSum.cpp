class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        int n = nums.size();
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
        }
        if (sum % 2 == 1)
            return false;
        sum = sum / 2;
        vector<vector<int>> dp(n + 1, vector<int>(sum + 1, 0));
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= sum; j++) {
                if (j >= nums[i - 1]) {
                    dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - nums[i - 1]] + nums[i - 1]);
                }
                else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        return dp[n][sum] == sum ? true : false;
    }

    //bool canPartition(vector<int>& nums) { //利用滚动数组实现
    //	int sum = 0;
    //	int n = nums.size();
    //	for (int i = 0; i < nums.size(); i++){
    //		sum += nums[i];
    //	}
    //	if (sum % 2 == 1)
    //		return false;
    //	sum = sum / 2;
    //	vector<int> dp(sum + 1, 0);
    //	for (int i = 1; i <= n; i++){
    //		for (int j = sum; j >= nums[i - 1]; j--)
    //			dp[j] = max(dp[j], dp[j - nums[i - 1]] + nums[i - 1]);
    //	}
    //	return dp[sum] == sum ? true : false;
    //}
};