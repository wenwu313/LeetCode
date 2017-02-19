int lengthOfLongestSubstring(string s) {  
    if (s.empty()) return 0;  
    int begin = 0, end = 0;  
    int max = 1;  
    int dict[256];  
    for (int i = 0; i < 256; i++)  
        dict[i] = 0;  
    while (end<s.size()){  
        while (dict[s[end]] == 0 && end<s.size()){   //end != s.size() - 1  
            dict[s[end]] = 1;  
            end++;  
        }  
        if (end-begin> max)       
            max = end - begin;  
        while (s[begin] != s[end]){  
            dict[s[begin]] = 0;  
            begin++;  
        }  
        begin++;   
        end++;  
    }  
    return max;  
} 

int lengthOfLongestSubstring(string s) {  
    if (s.empty()) return 0;  
    int begin = 0, end = 0;  
    int max = 1;  
    int dict[256];  
    for (int i = 0; i < 256; i++)  
        dict[i] = 0;  
    while (end<s.size()){  
        while (dict[s[end]] == 0 && end<s.size()){   //end != s.size() - 1  
            dict[s[end]] = 1;  
            end++;  
        }  
        if (end-begin> max)       
            max = end - begin;  
        while (dict[s[end]] == 1)  
        {  
            dict[s[begin]] = 0;  
            begin++;  
        }  
    }  
    return max;  
}