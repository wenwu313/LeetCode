#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void nextPermutation(vector<int>& nums) {
	int i;
	for (i = nums.size() - 1; i > 0; --i){
		if (nums[i] > nums[i - 1])
			break;
	}
	if (i == 0)
		reverse(nums.begin(), nums.end());
	for (int k = nums.size() - 1; k >= i && i > 0; k--){
		if (nums[k] > nums[i - 1]){
			swap(nums[k], nums[i - 1]);
			break;			
		}
	}
	reverse(nums.begin() + i, nums.end());
}


int main()
{
	vector<int> nums = { 2,2,0,4,3,1};
	nextPermutation(nums);
	for (int i = 0; i < nums.size(); i++){
		cout << nums[i] << ' ';
	}
	cout << endl;
	cin.get();
	return 0;
}

