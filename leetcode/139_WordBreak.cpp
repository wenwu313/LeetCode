class Solution {
public:
	/*
	序列型动态规划
	dp[i]表示前i个字符能不能被dict完美划分（注意i和对应字符串中的位置）
	判断dp[i]，则需要遍历0~i中是否存在一个j，使得dp[j]=true而且s.substr(j,i-j)存在于dict中
	动态转移方程：dp[i]=dp[j] && s.substr(j,i-j)
	*/
	bool wordBreak(string s, vector<string>& wordDict) {
		unordered_map<string, int> wordMap;
		for (string str : wordDict)
			wordMap[str]++;
		int len = s.size() + 1;
		vector<bool> dp(len + 1, false);
		dp[0] = true;
		for (int i = 1; i <= len; i++){
			for (int j = i - 1; j >= 0; j--){
				if (dp[j] && wordMap[s.substr(j, i - j)]){
					dp[i] = true;
					break;
				}
			}
		}
		return dp[len];
	}
};