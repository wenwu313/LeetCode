class Solution {
public:
	int numSquares(int n) { //DP  
		vector<int> dp(n + 1, 0);
		for (int i = 1; i <= n; i++){
			int square = INT_MAX;
			for (int j = 1; j*j <= i; j++)
				square = min(square, dp[i - j*j] + 1);
			dp[i] = square;
		}
		return dp[n];
	}
};