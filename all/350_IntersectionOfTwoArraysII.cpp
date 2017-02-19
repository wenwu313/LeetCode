#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;

void moveZeroes(vector<int>& nums) {
	int begin = 0, cur = 0;
	while (cur < nums.size()){
		if (nums[cur] != 0){
			if (cur == begin){
				cur++;
				begin++;
			}
			else{
				swap(nums[begin], nums[cur]);
				cur++;
				begin++;
			}
		}
		else{
			cur++;
		}
	}
}

void moveZeroes(vector<int>& nums) {
	int j = 0;
	// move all the nonzero elements advance
	for (int i = 0; i < nums.size(); i++) {
		if (nums[i] != 0) {
			nums[j++] = nums[i];
		}
	}
	for (; j < nums.size(); j++) {
		nums[j] = 0;
	}
}

int main()
{   
	
	vector<int> nums = { 0, 1, 0, 3, 12 };
	moveZeroes(nums);
	for (int i = 0; i < nums.size(); i++){
		cout << nums[i] << ' ';
	}
	cout << endl;
	cin.get();
	return 0;
}

