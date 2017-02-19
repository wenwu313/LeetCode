#include<iostream>
#include<vector>
using namespace std;

int missingNumber(vector<int>& nums) {
	int res = nums.size();  
	for (int i = 0; i < nums.size(); i++){
		res ^= i;
		res ^= nums[i];
	}
	return res;
}

int main()
{
	vector<int> nums = { 0, 1, 3, 4, 5, 6, 7 };
	cout << missingNumber(nums) << endl;
	cin.get();
	return 0;
}

