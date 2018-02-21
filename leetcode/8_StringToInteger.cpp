class Solution {
public:
    bool isTrue = false;
    long long  myAtoi(string str) {
        int i = 0, minus = 1;
        long long result = 0;
        if (str.empty())
            return result;
        while (i < str.size()) {
            if (str[i] == ' ') {
                i++;
                continue;
            }
            if (str[i] == '-') {
                minus = -1;
                i++;
            }
            else if (str[i] == '+')
                i++;
            break;
        }
        while (i < str.size()) {
            if (str[i] >= '0' && str[i] <= '9') {
                result = result * 10 + minus*(str[i] - '0');
                if (minus == 1 && result >INT_MAX || minus == -1 && result < INT_MIN)
                    result = minus == 1 ? INT_MAX : INT_MIN;
                i++;
            }
            else
                break;
        }
        if (i == str.size())
            isTrue = true;
        return result;
    }

};