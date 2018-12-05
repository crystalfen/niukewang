class Solution {
public:
    string LeftRotateString(string str, int n) {
        //法一：定义一个辅助的字符串。
        /*
        string temp;
        if(str.size()==0) return temp;
        n = n % str.size();
        temp.append(str,n,str.size()-n); //从第n个字符到结尾复制到emp的尾部
        temp.append(str,0,n); //
        return temp;
        */
        //法二：
        if(str.size()==0) return str;
        int len = str.size();
        n = n % str.size();
        str += str;
        return str.substr(n, len);
    }
};
