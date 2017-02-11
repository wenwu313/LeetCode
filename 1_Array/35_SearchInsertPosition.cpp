#include<iostream>
#include<vector>
using namespace std;

int searchInsert(vector<int>& nums, int target) {
	int left = 0, right = nums.size() - 1;
	while (left <= right){
		int mid = (left + right) >> 1;
		if (nums[mid] == target ) return mid;
		else if (nums[mid] > target) right = mid - 1;
		else left = mid + 1;
	}
	return left;
}

int main()
{
	vector<int> a1 = { 1 };
	cout << searchInsert(a1,7) << endl;
	cin.get();
	return 0;
}