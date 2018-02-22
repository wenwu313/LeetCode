vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
    unordered_map<int, int> map;
    vector<int> result;
    for (int x : nums1) {
        if (map[x] == 0) {
            map[x]++;
        }
    }
    for (int x : nums2) {
        if (map[x]-->0)
            result.push_back(x);
    }
    return result;
}

vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
    unordered_set<int> m(nums1.begin(), nums1.end());
    vector<int> res;
    for (auto a : nums2)
        if (m.count(a)) {
            res.push_back(a);
            m.erase(a);
        }
    return res;
}
