#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int majorityElement1(vector<int>& nums) {
	sort(nums.begin(), nums.end());
	return nums[nums.size() >> 1];
}

int majorityElement(vector<int>& nums) {
	int result = nums[0];
	int times = 1;
	for (int i = 1; i < nums.size(); i++){
		if (times == 0){
			result = nums[i];
			times = 1;
		}
		if (result == nums[i]) times++;
		else times--;
	}
	return result;
}

int main()
{
	vector<int> a1 = { 1, 2, 2, 4, 2, 5, 2, 3, 2, 2, 3, 2 };
	cout << majorityElement(a1) << endl;
	cin.get();
	return 0;
}