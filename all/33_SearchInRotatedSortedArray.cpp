#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

int search(vector<int>& nums, int target) {
	if (nums.empty()) return -1;
	int left = 0, right = nums.size() - 1;
	while (left < right){
		int mid = (left + right) >> 1;
		if (nums[mid] == target)
			return mid;
		if (nums[mid] >= nums[left]){
			if (target >= nums[left] && target < nums[mid])
				right = mid - 1;
			else
				left = mid + 1;
		}
		else{
			if (target>nums[mid] && target <= nums[right])
				left = mid + 1;
			else
				right = mid - 1;
		}
	}
	return nums[left] == target ? left : -1;
}

int main()
{
	vector<int> nums = { 3, 4, 5, 6, 1, 2 };
	cout << search(nums, 4) << endl;
	cin.get();
	return 0;
}

