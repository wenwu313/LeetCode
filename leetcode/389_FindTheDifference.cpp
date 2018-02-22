char findTheDifference(string s, string t) {
    unordered_map<char, int> map;
    for (char ch : t) {
        map[ch]++;
    }
    for (char ch : s) {
        map[ch]--;
    }
    for (auto it : map) {
        if (it.second != 0)
            return it.first;
    }
}


char findTheDifference1(string s, string t) {
    char r = 0;
    for (char c : s) r ^= c;
    for (char c : t) r ^= c;
    return r;
}