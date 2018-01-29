int firstUniqChar(string s) {
    unordered_map<char,int> map;
    for(char ch:s){
        map[ch]++;
    }
    for(int i = 0;i<s.size();i++){
        if(map[s[i]]==1)
            return i;
    }
    return -1;
}    

//java代码
int firstUniqChar(String s) {
    int freq[] = new int[26];
    for (int i = 0; i < s.length(); i++)
        freq[s.charAt(i) - 'a'] ++;
    for (int i = 0; i < s.length(); i++)
    if (freq[s.charAt(i) - 'a'] == 1)
        return i;
    return -1;
}
