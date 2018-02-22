class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0")
            return "0";
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        string res = "";
        int pos = 0, carry;
        for (int i = 0; i<num1.size(); i++) {
            pos = i;
            carry = 0;
            for (int j = 0; j<num2.size(); j++) {
                int temp = (num1[i] - '0')*(num2[j] - '0') + carry;
                if (pos<res.size()) {
                    temp += res[pos] - '0';
                    res[pos] = temp % 10 + '0';
                }
                else
                    res.append(1, temp % 10 + '0');
                carry = temp / 10;
                pos++;
            }
            if (carry>0)
                res.append(1, carry + '0');
        }
        reverse(res.begin(), res.end());
        return res;
    }
};