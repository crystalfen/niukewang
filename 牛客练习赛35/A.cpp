#include<iostream>
using namespace std;

int main()
{
    int number;
    cin>>number; //������������
    for(int i = 0; i < number; i++)
    {
        long long val;
        cin>>val;
        bool include1 = true; //��һ�����ֳ�������ʱ�������Ƿ����1.��ʼ��Ϊtrue,������1.
        if(val<= 3)
        {
            cout<<"NO"<<endl;
            continue;
        }
        while(val%2==0) //��4��ʼ������������Ƕ����ư����������
        {
            val = val / 2;
            include1 = false; // �Ѿ���2��������˵�������ư���������1��
        }
        if(val==1) //��һ�����������ܱ�2һֱ����ֱ������1����4,8,16,32����������Щ��һ���Ƕ����ư�������
        {
            cout<<"YES"<<endl;
            continue;
        }
        // �ڶ���������������ٱ�2������Ҳ������1ʱ��
        //����Ƕ����ư�������˵����С���Ǹ�����������������1����һ������Ȼ���Ա�2��������2*2*...*2*(1+2*2*...*2*1);
        val = val - 1;
        while(val % 2==0)
        {
            val = val / 2;
        }
        if(val==1 && !include1) // ����ڶ�������� �Ҳ���1����һ��������������ɡ����yes������,NO
        {
            cout<<"YES"<<endl;
        }
        else
        {
            cout<<"NO"<<endl;
        }
    }
    return 0;
}
