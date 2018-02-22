class Solution {
public:
    int countPrimes(int n) { //埃拉托斯特尼筛法  2到n所有素数  
        vector<bool> nums(n, true);
        for (int i = 2; i < sqrt(n); i++) {
            if (!nums[i]) continue;
            int j = i*i;
            while (j < n) {
                nums[j] = false;
                j += i;
            }
        }
        int result = 0;
        for (int i = 2; i < n; i++) {
            if (nums[i])
                result++;
        }
        return result;
    }
};