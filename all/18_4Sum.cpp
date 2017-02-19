#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<vector<int>> fourSum(vector<int>& nums, int target)
{
	vector<vector<int>> result;
	if (nums.size() < 4)
		return result;
	sort(nums.begin(), nums.end());
	for (int i = 0; i < nums.size() - 3; i++){
		if (i>0 && nums[i] == nums[i - 1])
			continue;
		for (int j = i + 1; j < nums.size() - 2; j++){
			if (j>i + 1 && nums[j] == nums[j - 1])
				continue;
			int start = j + 1, end = nums.size() - 1;
			while (start < end){
				int sum = nums[i] + nums[j] + nums[start] + nums[end];
				if (sum < target) start++;
				else if (sum > target) end--;
				else{
					result.push_back(vector<int>{nums[i], nums[j], nums[start++], nums[end--]});
					while (start < end && nums[start] == nums[start - 1]) start++;
					while (start < end && nums[end] == nums[end + 1]) end--;
				}
			}
		}	
	}
	return result;
}

int main()
{
	int a[] = { 1, 0, -1, 0, -2, 2 };
	int size = sizeof(a) / sizeof(int);
	vector<int> vec_a(a, a + size);
	vector<vector<int>> solution;
	solution = fourSum(vec_a, 0);
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


