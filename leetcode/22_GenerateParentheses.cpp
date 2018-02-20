class Solution {
public:
    void addingpar(vector<string> &res,string str,int left,int right){
        if(0==left && 0==right)
            res.push_back(str);
        if(left>0)
            addingpar(res,str+"(",left-1,right);
        if(left<right)
            addingpar(res,str+")",left,right-1);         
    }
    
    
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        addingpar(res,"",n,n);
        return res;
    }
};
