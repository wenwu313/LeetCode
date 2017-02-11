#include<iostream>
#include<vector>
using namespace std;

bool searchMatrix(vector<vector<int>>& matrix, int target) {
	int rows = matrix.size();
	if (matrix.empty()) return false;
	int j = matrix[0].size() - 1, i = 0;
	while (j >= 0 && i < rows){
		if (matrix[i][j]>target) j--;
		else if(matrix[i][j] < target) i++;
		else return true;
	}
	return false;
}

bool searchMatrix1(vector<vector<int>>& matrix, int target) {
	// treat the matrix as an array, just taking care of indices
	// [0..n*m]
	// (row, col) -> row*n + col
	// i -> [i/n][i%n]
	if (matrix.empty())
	{
		return false;
	}
	int m = matrix.size(), n = matrix[0].size();
	int start = 0, end = m*n - 1;
	while (start <= end)
	{
		int mid = start + (end - start) / 2;
		int e = matrix[mid / n][mid%n];
		if (target < e)
		{
			end = mid - 1;
		}
		else if (target > e)
		{
			start = mid + 1;
		}
		else
		{
			return true;
		}
	}
	return false;
}

int main()
{
	vector<vector<int>> mat = { { 1, 3, 5, 7 }, { 10, 11, 16, 20 }, { 23, 30, 34, 50 } };
	//for (int i = 0; i < 3; i++){
	//	for (int j = 0; j < 4; j++){
	//		cout << mat[i][j] << ' ';
	//	}
	//	cout << endl;
	//}
	int n = 50;
	cout << searchMatrix(mat,n) << endl;
	cin.get();
	return 0;
}