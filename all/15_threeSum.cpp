#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<vector<int>> threeSum(vector<int>& nums)
{
	vector<vector<int>> result;
	if (nums.size()<3)
		return result;
	sort(nums.begin(), nums.end());
	for (int i = 0; i < nums.size() - 2; i++){
		if (i>0 && nums[i] == nums[i - 1])
			continue;
		int target = -nums[i];
		int start = i + 1, end = nums.size() - 1;
		while (start < end){
			int sum = nums[start] + nums[end];
			if (sum < target) start++;
			else if (sum > target) end--;
			else{
				result.push_back(vector<int>{nums[i], nums[start++], nums[end--]});
				while (start < end && nums[start] == nums[start - 1]) start++; 
				while (start < end && nums[end] == nums[end + 1]) end--;
			}
		}
	}
	return result;
}

int main()
{
	int a[] = { -1, 0, 1, 2, -1, -4 };
	int size = sizeof(a) / sizeof(int);
	vector<int> vec_a(a, a + size);
	vector<vector<int>> solution;
	solution = threeSum(vec_a);

	for (int i = 0; i < solution.size(); i++){
		vector<int> temp = solution[i];
		for (int j = 0; j < temp.size(); j++){
			cout << solution[i][j] << ' ';
		}
		cout << endl;
	}

	cin.get();
	return 0;
}