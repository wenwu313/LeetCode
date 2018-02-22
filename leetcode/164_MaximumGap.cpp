class Solution {
public:
    int maximumGap(vector<int> &num) {
        if (num.size() < 2)
            return 0;
        int size = num.size();
        int Min = num[0];
        int Max = num[0];
        for (int i = 1; i < size; ++i) {
            Max = max(Max, num[i]);
            Min = min(Min, num[i]);
        }
        int gap = (Max - Min) / (size - 1) + 1;
        int bucketNum = (Max - Min) / gap + 1;
        vector<int> bucketsMin(bucketNum, INT_MAX);
        vector<int> bucketsMax(bucketNum, INT_MIN);
        for (int i = 0; i < size; ++i) {
            if (num[i] == Max || num[i] == Min)
                continue;
            int index = (num[i] - Min) / gap;
            bucketsMin[index] = min(bucketsMin[index], num[i]);
            bucketsMax[index] = max(bucketsMax[index], num[i]);
        }
        int maxGap = 0;
        int pre = Min;
        for (int i = 0; i < bucketNum; ++i) {
            if (bucketsMin[i] == INT_MAX || bucketsMax[i] == INT_MIN)
                continue;
            maxGap = max(maxGap, bucketsMin[i] - pre);
            pre = bucketsMax[i];
        }
        maxGap = max(maxGap, Max - pre);
        return maxGap;
    }
};