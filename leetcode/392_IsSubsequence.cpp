class Solution {
public:
    bool isSubsequence(string s, string t) {
        int len1 = s.size(), len2 = t.size(), k1 = 0, k2 = 0;
        while (k1<len1 && k2<len2) {
            if (s[k1] == t[k2]) k1++;
            k2++;
        }
        return k1 == len1;
    }
};