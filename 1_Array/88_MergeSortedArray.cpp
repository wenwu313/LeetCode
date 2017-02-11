#include<iostream>
#include<vector>
using namespace std;

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
	int i = m - 1, j = n - 1, k = m + n - 1;
	while (i >= 0 && j >= 0){
		if (nums1[i] > nums2[j]) nums1[k--] = nums1[i--];
        else nums1[k--] = nums2[j--];
	}
	
	while (j >= 0){ 
		nums1[j] = nums2[j];
		j--;
	}	
}

int main()
{
	int a1[] = { 1, 4, 6, 9 };
	int size1 = sizeof(a1) / sizeof(int);
	int a2[] = { 1, 5, 7, 8, 10 };
	int size2 = sizeof(a2) / sizeof(int);
	vector<int> vec_a1(a1, a1 + size1);
	vector<int> vec_a2(9);
	for (int i = 0; i < size2; i++) vec_a2[i] = a2[i];	
	merge(vec_a2, size2, vec_a1, size1);
	for (int i = 0; i < 9; i++) cout << vec_a2[i] << endl;
	cin.get();
	return 0;
}
