class Solution {
public:
	void replaceSpace(char *str,int length) {
        //话说， length代表的str的长度，但不是该字符串的长度
        int count = 0; //统计字符串的长度
        for(int i = 0 ; i < length; i++)
        {
            if(str[i]==' ')
                count++;
        }
        //从后往前替换。第j个空格后的所有元素都像后移动j*2个位置
        if(length < 1) return;
        for(int j = length - 1; j>=0 ; j--)
        {
            if(str[j] != ' ')
            {
                str[j+count*2] = str[j];

            }
            else
            {
                str[j+count*2] = '0';
                str[j+count*2-1] = '2';
                str[j+count*2-2] = '%';
                count--;
            }
        }

	}
};
