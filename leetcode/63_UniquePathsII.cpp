#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


//我的比较挫的写法
int uniquePathsWithObstacles(vector<vector<int>>& grid) {
	int m = grid.size();
	int n = grid[0].size();
	vector<int> nums(n, 1);
	for (int i = 0; i < n; i++){
		if (grid[0][i] == 1){
			for (int j = i; j < n; j++){
				nums[j] = 0;
			}
			break;
		}
	}
	for (int i = 1; i < m; i++){
		if (nums[0] == 1){
			if (grid[i][0] == 1)
				nums[0] = 0;
		}	
		for (int j = 1; j < n; j++){
			if (grid[i][j] == 1)
				nums[j] = 0;
			else
				nums[j] = nums[j - 1] + nums[j];
		}
	}
	return nums[n - 1];
}

int uniquePathsWithObstacles(vector<vector<int>>& grid){
	int width = grid[0].size();
	vector<int> dp(width);
	dp[0] = 1;
	for (vector<int> row : grid) {
		for (int j = 0; j < width; j++) {
			if (row[j] == 1)
				dp[j] = 0;
			else if (j > 0)
				dp[j] += dp[j - 1];
		}
	}
	return dp[width - 1];
}



int main()
{   
	vector<vector<int>> obstacleGrid = { { 0, 0, 0 }, { 0, 1, 0 }, { 0, 0, 0 } };
	cout << uniquePathsWithObstacles(obstacleGrid) << endl;
	cin.get();
	return 0;
}

