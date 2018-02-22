#include<iostream>
#include<vector>
using namespace std;

int removeElement(vector<int>& nums, int val) {
    int begin = 0;
    for (int i = 0; i < nums.size(); i++) {
        if (val != nums[i]) nums[begin++] = nums[i];
    }
    return begin;
}

int main()
{
    int a[] = { 1, 2, 3, 4, 2, 2, 3, 2 };
    int size = sizeof(a) / sizeof(int);
    vector<int> vec_a(a, a + size);
    cout << removeElement(vec_a, 2) << endl;
    cin.get();
    return 0;
}