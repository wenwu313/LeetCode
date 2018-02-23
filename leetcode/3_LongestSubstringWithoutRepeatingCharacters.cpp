class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.empty())
            return 0;
        int begin = 0, end = 0, maxlen = 1;
        unordered_map<char, int> map0;
        while (end<s.size()) {
            while (end<s.size() && map0[s[end]] == 0) {
                map0[s[end]] = 1;
                end++;
            }
            maxlen = max(end - begin, maxlen);
            while (map0[s[end]] == 1) {
                map0[s[begin]] = 0;
                begin++;
            }
        }
        return maxlen;
    }
};