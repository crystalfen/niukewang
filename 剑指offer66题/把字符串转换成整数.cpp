class Solution {
public:
    int StrToInt(string str) {
        //�Ӻ���ǰ�����������з���ֵ�ַ��Ҳ��ǵ�0λ��ֱ�����Ϊ0. ������������1��10��100�����������ۼ�
        int len = str.size();
        if(str.size()<1) return 0;
        int res = 0;
        int mul = 1;
        for(int i = str.size()-1; i>0; i--) //i=0��������
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
