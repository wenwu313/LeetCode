class Solution {
public:
	int partition(vector<int> &nums, int start, int end){
		int x = nums[end], i = start - 1;
		for (int j = start; j<end; j++){
			if (nums[j]>x)
				swap(nums[++i], nums[j]);
		}
		swap(nums[++i], nums[end]);
		return i;
	}


	int findKthLargest(vector<int>& nums, int k) {
		int left = 0, right = nums.size() - 1;
		while (left <= right){
			int mid = partition(nums, left, right);
			if (mid>k - 1) right = mid - 1;
			else if (mid<k - 1) left = mid + 1;
			else break;
		}
		return nums[k - 1];
	}
};