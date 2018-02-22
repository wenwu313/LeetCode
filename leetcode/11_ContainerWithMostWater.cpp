//暴力搜索  超时 时间复杂度O(N^2)
int maxArea(vector<int>& height) {
    int area = 0;
    for (int i = 0; i < height.size() - 1; ++i) {
        for (int j = i + 1; j < height.size(); ++j) {
            int temp = min(height[i], height[j])*(j - i);
            if (temp>area)
                area = temp;
        }
    }
    return area;
}

//头尾往中间移  较短的一边先移  移到比自己大的边  O(N)
int maxArea(vector<int>& height) {
    int i = 0, j = height.size() - 1;
    int area = 0;
    while (i < j) {
        int temp = min(height[i], height[j])*(j - i);
        if (temp>area)
            area = temp;
        if (height[i] < height[j])
            ++i;
        else
            --j;
    }
    return area;
}

int maxArea(vector<int>& height) {
    int water = 0;
    int i = 0, j = height.size() - 1;
    while (i < j) {
        int h = min(height[i], height[j]);
        water = max(water, (j - i) * h);
        while (height[i] <= h && i < j) i++;
        while (height[j] <= h && i < j) j--;
    }
    return water;
}