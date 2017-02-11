#include<iostream>
#include<vector>
using namespace std;

int findMin(vector<int>& nums) {
	int index1 = 0, index2 = nums.size() - 1;
	int mid = index1;
	while (nums[index1] > nums[index2]){
		if (index2 - index1 == 1){
			mid = index2;
			break;
		}			
		mid = (index1 + index2) >> 1;
		if (nums[mid] >= nums[index1])
			index1 = mid;
		else index2 = mid;
	}
	return nums[mid];
}

int findMin(vector<int> &num) {
	int start = 0, end = num.size() - 1;
	while (start<end) {
		if (num[start]<num[end])
			return num[start];
		int mid = (start + end) / 2;
		if (num[mid] >= num[start]) 
			start = mid + 1;
		else
			end = mid;	
	}
	return num[start];
}

int main()
{
	vector<int> nums = {4,5,6,7,0,1,2};
	cout << findMin(nums) << endl;
	cin.get();
	return 0;
}