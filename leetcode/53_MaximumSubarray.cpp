#include<iostream>
#include<vector>
using namespace std;

int maxSubArray(vector<int>& nums) {
	int sum = nums[0];
	int result = nums[0];
	for (int i = 1; i < nums.size(); i++){
		if (sum>0) sum += nums[i];
		else sum = nums[i];
		if (sum > result) result = sum;
	}
	return result;
}

int main()
{
	vector<int> a1 = { -2, 1, -3, 4, -1, 2, 1, -5, 4 };
	cout << maxSubArray(a1)<<endl;
	cin.get();
	return 0;
}