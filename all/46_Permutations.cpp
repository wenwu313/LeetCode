#include<iostream>
#include<vector>
using namespace std;

void permuteRecursive(vector<int>& nums, int begin, vector<vector<int>> &result)
{
	if (begin == nums.size() - 1){
		result.push_back(nums);
		return;
	}
	for (int i = begin; i < nums.size(); i++){
		swap(nums[begin], nums[i]);
		permuteRecursive(nums, begin + 1, result);
		swap(nums[begin], nums[i]);
	}

}

vector<vector<int>> permute(vector<int>& nums) {
	vector<vector<int>> result;
	if (nums.empty()) return result;	
	permuteRecursive(nums, 0, result);
	return result;
}

int main()
{
	vector<int> a1 = {1,2,3};
	vector<vector<int>> res = permute(a1);
	for (int i = 0; i < res.size(); i++){
		for (int j = 0; j < res[0].size(); j++){
			cout << res[i][j] << ' ';
		}
		cout << endl;
	}
	cin.get();
	return 0;
}