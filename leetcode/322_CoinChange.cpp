class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, -1);
        dp[0] = 0;
        for (int i = 1; i <= amount; i++) {
            for (int coin : coins) {
                if (i >= coin && dp[i - coin] != -1) {
                    if (dp[i] == -1)
                        dp[i] = dp[i - coin] + 1;
                    else
                        dp[i] = min(dp[i], dp[i - coin] + 1);
                }
            }
        }
        return dp[amount];
    }
};

//Another DP implmentation, same idea above 
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        const int MAX = amount + 1;
        vector<int> dp(amount + 1, MAX);
        dp[0] = 0;

        for (int i = 1; i <= amount; i++) {
            for (int j = 0; j<coins.size(); j++) {
                if (i >= coins[j]) {
                    dp[i] = min(dp[i], dp[i - coins[j]] + 1);
                }
            }
        }

        return dp[amount] == MAX ? -1 : dp[amount];
    }
};