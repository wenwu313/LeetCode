#include<iostream>
#include<vector>
using namespace std;

int missingNumber(vector<int>& nums) {
	int res = nums.size();  
	for (int i = 0; i < nums.size(); i++){
		res ^= i;
		res ^= nums[i];
	}
	return res;
}

int main()
{
	vector<int> nums = { 0, 1, 3, 4, 5, 6, 7 };
	cout << missingNumber(nums) << endl;
	cin.get();
	return 0;
}


// int missingNumber(vector<int>& nums) { //二分 
//     int n = nums.size();  
//     sort(nums.begin(), nums.end());  
//     int left = 0, right = n, mid = 0;  
//     while (left<right){  
//         mid = (left + right) >> 1;  
//         if (nums[mid]>mid)  
//             right = mid;  
//         else  
//             left = mid + 1;  
//     }  
//     return left;  
// }  

// int missingNumber(vector<int>& nums) {   //交换，用索引标注
//     int n = nums.size();  
//     for (int i = 0; i<n; i++){  
//         while (nums[i]>0 && nums[i] <= n && nums[i] != i + 1)  
//             swap(nums[nums[i] - 1], nums[i]);  
//     }  
//     for (int i = 0; i<n; i++)  
//     if (nums[i] != i + 1) return i + 1;  
//     return 0;  
// } 