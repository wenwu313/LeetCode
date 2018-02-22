class Solution {
public:
    string countAndSay(int n) {
        if (n <= 0)
            return NULL;

        //n=1时，结果为"1"
        string ret = "1";
        if (n == 1)
            return ret;
        else
        {
            for (int i = 2; i <= n; i++)
                ret = Count(ret);
        }//else
        return ret;

    }

    string Count(const string &str)
    {
        int size = strlen(str.c_str());
        stringstream ret;
        char flag = str[0];
        int count = 0, i = 0;
        while (i < size)
        {
            while (i<size && str[i] == flag)
            {
                count++;
                i++;
            }//while
            ret << count << flag;
            flag = str[i];
            count = 0;
            i = i - 1;
        }//for
        return ret.str();
    }
};