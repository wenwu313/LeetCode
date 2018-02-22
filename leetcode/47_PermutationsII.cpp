#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void permuteUnique(vector<int> &nums, vector<vector<int>> &result, int begin) {
    if (begin == nums.size() - 1) {
        result.push_back(nums);
        return;
    }
    for (int i = begin; i < nums.size(); ++i) {
        int beginTemp = begin;
        while (i>beginTemp) {
            if (nums[i] == nums[beginTemp])
                break;
            ++beginTemp;
        }
        if (i != beginTemp)
            continue;
        swap(nums[begin], nums[i]);
        permuteUnique(nums, result, begin + 1);
        swap(nums[begin], nums[i]);
    }
}

vector<vector<int>> permuteUnique(vector<int>& nums) {
    vector<vector<int>> result;
    if (nums.empty()) return result;
    vector<int> temp;
    permuteUnique(nums, result, 0);
    return result;
}


int main()
{
    vector<int> nums = { 1,2,3 };
    vector<vector<int>> ans = permuteUnique(nums);
    for (int i = 0; i < ans.size(); i++) {
        for (int j = 0; j < ans[i].size(); j++) {
            cout << ans[i][j] << ' ';
        }
        cout << endl;
    }
    cin.get();
    return 0;
}

