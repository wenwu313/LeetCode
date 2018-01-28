#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int uniquePaths(int m, int n) {
	if (m < 1 || n < 1) return 0;
	vector<int> nums(n, 1);
	for (int i = 1; i < m; i++){
		for (int j = 1; j < n; j++){
			nums[j] = nums[j - 1] + nums[j];
		}		
	}
	return nums[n - 1];
}

int main()
{
	cout << uniquePaths(3, 3) << endl;
	cin.get();
	return 0;
}

