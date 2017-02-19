#include<iostream>
#include<vector>
using namespace std;

int singleNumber1(vector<int>& nums) {
	int ans = 0;
	for (int i = 0; i < 32; i++) {
		int sum = 0;
		for (int j = 0; j < nums.size(); j++) {
			if (((nums[j] >> i) & 1) == 1)  sum++;			
			sum %= 3;
		}
		if (sum != 0) {
			ans |= sum << i;
		}
	}
	return ans;
}

int singleNumber(vector<int>& nums) {
	int ans = 0;
	for (int i = 0; i < 32; i++) {
		int sum = 0;
		for (int j = 0; j < nums.size(); j++) {
			sum += (nums[j] >> i) & 1;
		}
		sum %= 3;
		ans |= sum << i;
	}
	return ans;
}

int main()
{
	vector<int> a1 = { 2, 3, 1, 2, 1, 1, 2 };
	cout << singleNumber(a1) << endl;
	cin.get();
	return 0;
}