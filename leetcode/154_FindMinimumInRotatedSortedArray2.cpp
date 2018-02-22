#include<iostream>
#include<vector>
using namespace std;

int MinInorder(vector<int> &nums, int index1, int index2) {
    int result = nums[index1];
    for (int i = index1 + 1; i <= index2; i++) {
        if (result > nums[i])
            result = nums[i];
    }
    return result;
}

int findMin(vector<int>& nums) {
    int index1 = 0, index2 = nums.size() - 1;
    int mid = index1;
    while (nums[index1] >= nums[index2]) {
        if (index2 - index1 == 1) {
            mid = index2;
            break;
        }
        mid = (index1 + index2) >> 1;
        if (nums[index1] == nums[index2] && nums[mid] == nums[index2])
            return MinInorder(nums, index1, index2);
        if (nums[mid] >= nums[index1])
            index1 = mid;
        else if (nums[mid] <= nums[index1])
            index2 = mid;
    }
    return nums[mid];
}

int findMin(vector<int> &num) {
    int start = 0;
    int end = num.size() - 1;
    int mid = 0;
    while (start < end) {
        mid = start + (end - start) / 2;

        if (num[mid] > num[end]) {
            end = mid + 1;
        }
        else if (num[mid] < num[end]) {
            end = mid;
        }
        else end--;
    }
    return num[start];
}

int findMin1(vector<int> &num) {
    int start = 0;
    int end = num.size() - 1;
    int mid;
    while (start<end) {
        if (num[start]<num[end])
            break;
        mid = start + (end - start) / 2;
        if (num[mid]>num[end]) {
            start = mid + 1;
        }
        else if (num[mid] == num[end]) {
            start++;
            end--;
        }
        else
            end = mid;
    }
    return num[start];
}

int findMin2(vector<int> &num) {
    int start = 0, end = num.size() - 1;
    while (start<end) {
        int mid = (start + end) / 2;
        if (num[mid]>num[end]) start = mid + 1;
        else end = mid;
    }
    return num[start];
}

int main()
{
    vector<int> nums = { 4,5,6,7,0,1,2 };
    cout << findMin(nums) << endl;
    cin.get();
    return 0;
}

