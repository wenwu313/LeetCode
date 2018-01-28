#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int removeDuplicates(vector<int>& nums) {
	if (nums.empty()) return 0;
	int cnt = 0;
	for (int i = 1; i < nums.size(); i++){
		if (nums[i]>nums[cnt])
			nums[++cnt] = nums[i];
	}
	return cnt + 1;
}

int removeDuplicates(vector<int>& nums) {
	int i = 0;
	for (int n : nums)
	if (!i || n > nums[i - 1])
		nums[i++] = n;
	return i;
}

int main()
{   
	vector<int>  nums = { 1, 1, 1, 2, 2, 3 };
	int n = removeDuplicates(nums);
	cout << n << endl;
	for (int i = 0; i < n; i++){
		cout << nums[i] << ' ';
	}
	cout << endl;
	cin.get();
	return 0;
}

