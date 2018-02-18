class Solution {
public:
	// As the hint said, checking the n with ranging from 7 to 10 to discover the regularities.
	// n = 7,    3*4 = 12
	// n = 8,  3*3*2 = 18
	// n = 9,  3*3*3 = 27
	// n = 10, 3*3*4 = 36
	// n = 11, 3*3*3*2 = 54
	//
	// we can see we can break the number by 3 if it is greater than 4;
	//
	int integerBreak(int n) {
		if (n == 2) return 1;
		if (n == 3) return 2;
		int result = 1;
		while (n > 4) {
			result *= 3;
			n -= 3;
		}
		result *= n;
		return result;
	}

	int integerBreak1(int n) {
		vector<int> dp(n + 1, 1);
		for (int i = 2; i <= n; i++) {
			for (int j = 1; j <= i - 1; j++) {
				if (i - j <= 4)
					dp[i] = max((i - j)*j, dp[i]);
				else
					dp[i] = max(dp[i - j] * j, dp[i]);
			}
		}
		return dp[n];
	}
};