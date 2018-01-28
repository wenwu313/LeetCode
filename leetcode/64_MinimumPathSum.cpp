#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//¶¯Ì¬¹æ»®  S[i][j] = min(S[i - 1][j], S[i][j - 1]) + grid[i][j]
int minPathSum(vector<vector<int>>& grid) {
	if (grid.empty()) return 0;    
	int rows = grid.size();
	int cols = grid[0].size();
	for (int i = 1; i < rows; i++)
		grid[i][0] += grid[i - 1][0];
	for (int i = 1; i < cols; i++)
		grid[0][i] += grid[0][i - 1];

	for (int i = 1; i < rows; i++){
		for (int j = 1; j < cols; j++){
			grid[i][j] += min(grid[i - 1][j], grid[i][j - 1]);
		}
	}
	return grid[rows - 1][cols - 1];
}

int main()
{
	vector<vector<int>> grid = { { 1, 2, 3 }, { 4, 5, 6 }, { 7, 8, 9 } };
	cout << minPathSum(grid) << endl;
	cin.get();
	return 0;
}

