#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;

string addStrings(string num1, string num2) {
    if (num1.empty() || num2.empty())
        return num1.empty() ? num2 : num1;
    int m = num1.size() - 1, n = num2.size() - 1;
    string result = "";
    int carry = 0, temp;
    while (m >= 0 || n >= 0) {
        temp = (m >= 0 ? num1[m--] - '0' : 0) + (n >= 0 ? num2[n--] - '0' : 0) + carry;
        result = char(temp % 10 + '0') + result;
        carry = temp / 10;
    }
    if (carry > 0)
        result = char(carry + '0') + result;
    return result;
}

int main()
{
    cout << addStrings("123", "9956") << endl;
    cin.get();
    return 0;
}

