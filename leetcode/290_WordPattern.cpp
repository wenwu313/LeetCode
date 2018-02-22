class Solution {
public:
    bool wordPattern(string pattern, string str) {
        istringstream strcin(str);
        string s;
        vector<string> vs;
        while (strcin >> s) vs.push_back(s);
        if (pattern.size() != vs.size()) return false;
        unordered_map<string, int> s2i;
        unordered_map<char, int> c2i;
        for (int i = 0; i < vs.size(); ++i) {
            if (s2i[vs[i]] != c2i[pattern[i]])
                return false;
            s2i[vs[i]] = c2i[pattern[i]] = i + 1;
        }
        return true;
    }
};