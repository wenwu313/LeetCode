//more about lambda,you can reference:http://blog.csdn.net/taoyanqi8932/articl  
class Solution {  
public:  
    string largestNumber(vector<int> &num) {  
        sort(num.begin(), num.end(), [](int a, int b){  
            return to_string(a)+to_string(b) > to_string(b)+to_string(a);  
        });  
        string ans;  
        for(int i=0; i<num.size(); i++){  
            ans += to_string(num[i]);  
        }  
        return ans[0]=='0' ? "0" : ans;  
    }  
};  