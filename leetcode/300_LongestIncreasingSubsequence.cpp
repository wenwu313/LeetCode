class Solution {
public:
	int lengthOfLIS(vector<int>& nums) {
		if (nums.empty())
			return 0;
		vector<int> dp;
		dp.push_back(1);
		for (int i = 1; i < nums.size(); i++){
			int max_len = 1;
			for (int j = 0; j < i; j++){
				if (nums[i]>nums[j] && dp[j] + 1>max_len)
					max_len = dp[j] + 1;
			}
			dp.push_back(max_len);
		}
		int result = 0;
		for (int i = 0; i < dp.size(); i++){
			if (dp[i]>result)
				result = dp[i];
		}
		return result;
	}
};