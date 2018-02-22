#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;

int longestPalindrome(string s) {
    unordered_map<char, int> map;
    for (char ch : s) {
        map[ch]++;
    }
    int result = 0, odd = 0;
    for (auto pair : map) {
        if ((pair.second & 1) == 0) {
            result += pair.second;
        }
        else {
            odd = 1;
            result += pair.second - 1;
        }
    }
    return result + odd;
}


int main()
{
    cout << longestPalindrome("abccccddeeeee") << endl;
    cin.get();
    return 0;
}

