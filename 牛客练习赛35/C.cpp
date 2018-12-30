#include<iostream>
using namespace std;
typedef long long ll;
const ll mod = 233;
const int inf = 0x3fffffff;//ע��int���з��ŵģ�������Ϊ0xffffffff; inf��ʾ����֮���޷�����

int main()
{
    int GF[mod][mod]; //����GF���ֵ����������������ֵ֮���ܷ񵽴��Ҫ����ת��
    // 1.������ͬ������ֵһ����ת����0��ת��
    for(int i = 0 ; i < mod ; i++)
    {
        for(int j = 0 ; j < mod ; j++)
        {
            if(j==i) GF[i][j]=0;
            else GF[i][j] = inf;
        }
    }
    // 2.��������С��233��ֵ������������G(i)��F(i)Ԫ�ص�ֵ֮���ǿ��Ե���ģ�1��ת�������ǵñ�ֵ֤������ȵ�
    for(int i = 0; i < mod; i++)
    {
        int tem1 = (i*i*i+i*i) % mod;
        int tem2 = (i*i*i-i*i) % mod;
        GF[i][tem1] = min(GF[i][tem1],1);
        GF[i][tem2] = min(GF[i][tem2],1);
    }
    // 3. ��������i��j��ֵ�����Խ����м��k������i����ͨ��k����j�������ж��k��ѡ��ת��������С�ġ�
    for(int k = 0 ; k < mod; k++)
    {
        for(int i = 0 ; i < mod; i++)
        {
            for(int j = 0; j < mod; j++)
                if(GF[i][k]!=inf && GF[k][j] != inf)
                    GF[i][j] = min(GF[i][j], GF[i][k]+GF[k][j]);
        }
    }
    // ������������
    ll T;
    scanf("%lld", &T);
    while(T--)
    {
        ll A, B;
        scanf("%lld%lld", &A, &B);
        ll number = 0;
        if(A==B) {printf("%d\n", 0);continue;} // 1.��ȣ�0��
        if(B>=mod) {printf("%d\n", -1);continue;} // 2.B����233ʱ�϶����ܵ���
        if(A>=mod) {A= A%mod;} // 3. ��A����233ʱ���ȶ����������
        int tem1 = (A*A*A+A*A) % mod; // 4.��һ���Ƚ���G(i)��������F(i)����
        int tem2 = (A*A*A-A*A) % mod;
        number = min(GF[tem1][B], GF[tem2][B])+1; //ѡ���С���Ǹ���
        if(number>=inf) {printf("%d\n", -1);}
        else
        {
            printf("%lld\n", number);
        }

    }
    return 0;
}
