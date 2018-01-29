class Solution {
public:
	int numTrees(int n) {
		if (n <= 0)
			return -1;
		if (n == 1)
			return 1;
		vector<int> nums = { 1, 1 };
		for (int i = 2; i <= n; i++){
			int temp = 0;
			for (int j = 1; j <= i; j++){
				temp += nums[j - 1] * nums[i - j];
			}
			nums.push_back(temp);
		}
		return nums[n];
	}
};