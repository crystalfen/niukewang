class Solution {
public:
    string LeftRotateString(string str, int n) {
        //��һ������һ���������ַ�����
        /*
        string temp;
        if(str.size()==0) return temp;
        n = n % str.size();
        temp.append(str,n,str.size()-n); //�ӵ�n���ַ�����β���Ƶ�emp��β��
        temp.append(str,0,n); //
        return temp;
        */
        //������
        if(str.size()==0) return str;
        int len = str.size();
        n = n % str.size();
        str += str;
        return str.substr(n, len);
    }
};
