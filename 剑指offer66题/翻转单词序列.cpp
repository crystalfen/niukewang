class Solution {
public:
    string ReverseSentence(string str) {
        // 法一：新建一个字符串。
        string res;
        if (str.size()==1) return str;
        for(int i = str.size()-1; i>=0; i--)
        {
            int j = i;
            while(i>=0 && str[i]!=' ')
            {
                i--;
            }
            for(int k = i+1; k<=j;k++)
                res.push_back(str[k]);
            if(i!=-1)
                res.push_back(' ');
        }
        return res;
    }
};
