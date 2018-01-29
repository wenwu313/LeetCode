class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		if (nums.empty())
			return 0;
		int x = 0, isTwo = 0;
		for (int i = 1; i<nums.size(); i++){
			if (isTwo == 0 && nums[i] == nums[x]){
				nums[++x] = nums[i];
				isTwo++;
			}
			if (nums[i] > nums[x]){
				nums[++x] = nums[i];
				isTwo = 0;
			}
		}
		return x + 1;
	}
};