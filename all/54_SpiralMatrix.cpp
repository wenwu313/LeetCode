#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;

vector<int> spiralOrder(vector<vector<int>>& matrix) {
	vector<int> result;
	if (matrix.empty()) return result;
	int m = matrix.size() - 1, n = matrix[0].size() - 1;
	for (int i = 0, j = 0; i <= m && j <= n; i++, j++){
		for (int k = j; k <= n; k++){
			result.push_back(matrix[i][k]);
		}		

		for (int k = i + 1; k <= m; k++){
			result.push_back(matrix[k][n]);
		}
			
		for (int k = n - 1; k >= j && i != m; k--){
			result.push_back(matrix[m][k]);
		}		

		for (int k = m - 1; k > i && j!=n; k--){
			result.push_back(matrix[k][j]);
		}
		m--;
		n--;
	}
	return result;
}

int main()
{   
	vector<vector<int>> input = { { 1, 2, 3 }, { 4, 5, 6 }, { 7, 8, 9 } };
	vector<int> nums = spiralOrder(input);
	for (int i = 0; i < nums.size(); i++){
		cout << nums[i] << ' ';
	}
	cout << endl;
	cin.get();
	return 0;
}

