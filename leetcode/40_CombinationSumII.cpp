#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void combinationSum2(vector<int>& candidates, int target, vector<vector<int>> &result, vector<int> &temp, int begin)
{
    if (target == 0) {
        result.push_back(temp);
        return;
    }
    for (int i = begin; i < candidates.size() && target >= candidates[i]; ++i) {
        if (i != begin && candidates[i] == candidates[i - 1])
            continue;
        temp.push_back(candidates[i]);
        combinationSum2(candidates, target - candidates[i], result, temp, i + 1);
        temp.pop_back();
    }
}

vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    vector<vector<int>> result;
    vector<int> temp;
    sort(candidates.begin(), candidates.end());
    combinationSum2(candidates, target, result, temp, 0);
    return result;
}

int main()
{
    vector<int> nums = { 10, 1, 2, 7, 6, 1, 5 };
    vector<vector<int>> ans = combinationSum2(nums, 8);
    for (int i = 0; i < ans.size(); i++) {
        for (int j = 0; j < ans[i].size(); j++) {
            cout << ans[i][j] << ' ';
        }
        cout << endl;
    }
    cin.get();
    return 0;
}

