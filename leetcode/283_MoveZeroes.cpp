#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;

void moveZeroes(vector<int>& nums) {
    int begin = 0, cur = 0;
    while (cur < nums.size()) {
        if (nums[cur] != 0) {
            if (cur == begin) {
                cur++;
                begin++;
            }
            else {
                swap(nums[begin], nums[cur]);
                cur++;
                begin++;
            }
        }
        else {
            cur++;
        }
    }

}

int main()
{

    vector<int> nums = { 0, 1, 0, 3, 12 };
    moveZeroes(nums);
    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i] << ' ';
    }
    cout << endl;
    cin.get();
    return 0;
}

