#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
//中间找到一点 向两边扩
vector<int> searchRange1(vector<int>& nums, int target) {
    vector<int> ans = { -1, -1 };
    if (nums.empty()) return ans;
    int left = 0, right = nums.size() - 1;
    while (left <= right) {
        int mid = (left + right) >> 1;
        if (nums[mid] == target) {
            ans[0] = mid;
            ans[1] = mid;
            break;
        }
        if (nums[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }
    if (left>right)
        return ans;
    int i;
    for (i = ans[1]; i < nums.size();) {
        if (nums[i] == target)
            i++;
        else
            break;
    }
    ans[1] = i - 1;
    for (i = ans[0]; i >= 0;) {
        if (nums[i] == target)
            i--;
        else
            break;
    }
    ans[0] = i + 1;
    return ans;
}

//两次二分搜索 分别找最左点和最右点
vector<int> searchRange(vector<int>& nums, int target) {
    vector<int> ans(2, -1);
    if (nums.empty()) return ans;
    int left = 0, right = nums.size() - 1;
    while (left < right) {
        int mid = (left + right) >> 1;
        if (nums[mid] < target) left = mid + 1;
        else right = mid;
    }
    if (nums[left] != target) return ans;
    else ans[0] = left;
    right = nums.size() - 1;
    while (left < right) {
        int mid = ((left + right) >> 1) + 1;
        if (nums[mid] > target) right = mid - 1;
        else left = mid;
    }
    ans[1] = right;
    return ans;
}

int main()
{
    vector<int> nums = { 5, 7, 7, 8, 8, 10 };
    vector<int> ans = searchRange(nums, 8);
    cout << ans[0] << ' ' << ans[1] << endl;
    cin.get();
    return 0;
}

