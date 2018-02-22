#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void combinationSum(vector<int>& candidates, int target, int begin, vector<vector<int>> &result, vector<int> &temp)
{
    if (target < 0) return;
    if (target == 0) {
        result.push_back(temp);
        return;
    }
    for (int i = begin; i >= 0; i--) {
        temp.push_back(candidates[i]);
        combinationSum(candidates, target - candidates[i], i, result, temp);
        temp.pop_back();
    }
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<vector<int>> result;
    vector<int> temp;
    sort(candidates.begin(), candidates.end());
    combinationSum(candidates, target, candidates.size() - 1, result, temp);
    return result;
}

int main()
{
    vector<int> nums = { 1,2 };
    vector<vector<int>> ans = combinationSum(nums, 1);
    for (int i = 0; i < ans.size(); i++) {
        for (int j = 0; j < ans[i].size(); j++) {
            cout << ans[i][j] << ' ';
        }
        cout << endl;
    }
    cin.get();
    return 0;
}

