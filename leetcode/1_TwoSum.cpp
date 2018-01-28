#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target) 
{
	vector<int> ns = nums;
	sort(ns.begin(), ns.end());
	int a = 0, b = ns.size() - 1;
	while (a<b)
	   if (ns[a] + ns[b] < target) a++;
	   else if (ns[a] + ns[b] > target) b--;
	   else break;

	vector<int> index;
	for (int i = 0; i < ns.size(); i++){
		if (nums[i] == ns[a]) index.push_back(i);
		else if (nums[i] == ns[b]) index.push_back(i);
	}

	if (index[0]>index[1])
		swap(index[0], index[1]);
	return index;
}

int main()
{
	int a[] = { 2, 7, 11, 15 };
	int target = 9, size = sizeof(a) / sizeof(int);
	vector<int> vec_a(a, a + size), return_index;
	return_index = twoSum(vec_a, target);
    cout << "两个数的下标是"<<return_index[0] << "和" << return_index[1] << endl;
	cin.get();
	return 0;
}