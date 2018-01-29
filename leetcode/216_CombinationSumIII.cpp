#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void combinationSum3(int k, int n, int num, vector<int> &temp, vector<vector<int>> &result) {
	if (k == 0){
		if (n == 0)
			result.push_back(temp);
		return;
	}
	for (int i = num; i <= 9 && n >= i; i++){
		temp.push_back(i);
		combinationSum3(k - 1, n - i, i + 1, temp, result);
		temp.pop_back();
	}
}

vector<vector<int>> combinationSum3(int k, int n) {
	vector<vector<int>> result;
	vector<int> temp;
	combinationSum3(k, n, 1, temp, result);
	return result;
}

int main()
{
	vector<vector<int>> ans = combinationSum3(3, 9);
	for (int i = 0; i < ans.size(); i++){
		for (int j = 0; j < ans[i].size(); j++){
			cout << ans[i][j] << ' ';
		}
		cout << endl;
	}
	cin.get();
	return 0;
}

