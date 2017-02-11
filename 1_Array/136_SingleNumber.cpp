#include<iostream>
#include<vector>
using namespace std;

int singleNumber(vector<int>& nums) {
	for (int i = 0; i < nums.size(); i++){
		int status = 0;
		for (int j = 0; j < nums.size(); j++){
			if ((nums[i] == nums[j]) && (i != j)) status = 1;		
		}
		if (status == 0)
			return nums[i];
	}
	return -1;
}

int singleNumber1(vector<int>& nums) {
	int res = 0;
	for (int i = 0; i < nums.size(); i++){
		res = res^nums[i];
	}
	return res;
}

int main()
{
	vector<int> a1 = { 2, 3, 1, 2, 1 };
	cout << singleNumber(a1) << endl;
	cin.get();
	return 0;
}