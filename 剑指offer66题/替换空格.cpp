class Solution {
public:
	void replaceSpace(char *str,int length) {
        //��˵�� length�����str�ĳ��ȣ������Ǹ��ַ����ĳ���
        int count = 0; //ͳ���ַ����ĳ���
        for(int i = 0 ; i < length; i++)
        {
            if(str[i]==' ')
                count++;
        }
        //�Ӻ���ǰ�滻����j���ո�������Ԫ�ض�����ƶ�j*2��λ��
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
