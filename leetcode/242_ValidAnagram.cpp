class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> unmap;
        for (char ch : s) {
            unmap[ch]++;
        }
        for (char ch : t) {
            unmap[ch]--;
        }
        for (auto pair : unmap) {
            if (pair.second)
                return false;
        }
        return true;
    }
};
