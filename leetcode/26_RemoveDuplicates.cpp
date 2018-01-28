#include<iostream>
#include<vector>
using namespace std;

int removeDuplicates1(vector<int>& nums) {   //×Ô¼ºÐ´µÄ
	if (nums.size() <= 1) return nums.size();
	int count = 0;
	for (int i = 1; i < nums.size(); ++i){
		if (nums[count] != nums[i]) nums[++count] = nums[i];
	}
	return count + 1;
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
	int a[] = { 1 };
	int size = sizeof(a) / sizeof(int);
	vector<int> vec_a(a, a + size);
	int x = removeDuplicates(vec_a);
	for (int i = 0; i < x; i++){
		cout << vec_a[i] << endl;
	}
	cin.get();
	return 0;
}
