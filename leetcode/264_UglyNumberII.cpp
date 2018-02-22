class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> res(n, 1);
        int index2 = 0, index3 = 0, index5 = 0;
        for (int i = 1; i<n; i++) {
            res[i] = min(min(res[index2] * 2, res[index3] * 3), res[index5] * 5);
            if (res[i] == res[index2] * 2) index2++;
            if (res[i] == res[index3] * 3) index3++;
            if (res[i] == res[index5] * 5) index5++;
        }
        return res[n - 1];
    }
};