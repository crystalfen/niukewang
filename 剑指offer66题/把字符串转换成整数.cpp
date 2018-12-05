class Solution {
public:
    int StrToInt(string str) {
        //从后往前面遍历。如果有非数值字符且不是第0位，直接输出为0. 否则轮流乘以1，10，100，。。。并累加
        int len = str.size();
        if(str.size()<1) return 0;
        int res = 0;
        int mul = 1;
        for(int i = str.size()-1; i>0; i--) //i=0单独计算
        {
            if(str[i]-'0'<0 || str[i] - '0' > 9) return 0;
            res += mul * (str[i] - '0');
            mul *= 10;

        }
        if(str[0]=='+') return res;
        else if(str[0]=='-') return -res;
        else if(str[0]-'0'<0 || str[0] -'0'>9) return 0;
        else
        {
            res += mul * (str[0] - '0');
            return res;
        }

    }
};
