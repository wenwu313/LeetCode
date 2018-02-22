#include<iostream>
using namespace std;

int lengthOfLastWord(string s) {
    int end = s.size() - 1;
    int length = 0;
    while (end >= 0 && s[end] == ' ') end--;
    while (end >= 0 && s[end] != ' ') {
        length++;
        end--;
    }
    return length;
}

int main()
{
    string s1 = "Hello world asdafafagf  ";
    //cout << s1.c_str() << endl;  //´òÓ¡×Ö·û´®
    cout << lengthOfLastWord(s1) << endl;
    cin.get();
    return 0;
}