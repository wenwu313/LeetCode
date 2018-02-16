class Solution {
public:
	int lengthOfLIS(vector<int>& nums) {
		int maxlen = 0, len = nums.size();
		vector<int> dp(len, 1);
		for (int i = 0; i < len; i++) {
			for (int j = 0; j < i; j++) {
				if (nums[i] > nums[j])
					dp[i] = max(dp[i], dp[j] + 1);
			}
			maxlen = max(maxlen, dp[i]);
		}
		return maxlen;
	}
};