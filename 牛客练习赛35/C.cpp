#include<iostream>
using namespace std;
typedef long long ll;
const ll mod = 233;
const int inf = 0x3fffffff;//注意int是有符号的，不能设为0xffffffff; inf表示两点之间无法到达

int main()
{
    int GF[mod][mod]; //矩阵GF里的值代表行数和列数的值之间能否到达，需要几次转换
    // 1.首先相同的两个值一定能转换，0次转换
    for(int i = 0 ; i < mod ; i++)
    {
        for(int j = 0 ; j < mod ; j++)
        {
            if(j==i) GF[i][j]=0;
            else GF[i][j] = inf;
        }
    }
    // 2.对于任意小于233的值，它与它进行G(i)和F(i)元素的值之间是可以到达的，1次转换。但是得保证值不是相等的
    for(int i = 0; i < mod; i++)
    {
        int tem1 = (i*i*i+i*i) % mod;
        int tem2 = (i*i*i-i*i) % mod;
        GF[i][tem1] = min(GF[i][tem1],1);
        GF[i][tem2] = min(GF[i][tem2],1);
    }
    // 3. 对于任意i和j个值，可以借助中间点k，这样i可以通过k到达j，可能有多个k，选择转换次数最小的。
    for(int k = 0 ; k < mod; k++)
    {
        for(int i = 0 ; i < mod; i++)
        {
            for(int j = 0; j < mod; j++)
                if(GF[i][k]!=inf && GF[k][j] != inf)
                    GF[i][j] = min(GF[i][j], GF[i][k]+GF[k][j]);
        }
    }
    // 读入样例个数
    ll T;
    scanf("%lld", &T);
    while(T--)
    {
        ll A, B;
        scanf("%lld%lld", &A, &B);
        ll number = 0;
        if(A==B) {printf("%d\n", 0);continue;} // 1.相等，0次
        if(B>=mod) {printf("%d\n", -1);continue;} // 2.B大于233时肯定不能到达
        if(A>=mod) {A= A%mod;} // 3. 当A大于233时，先对它求余操作
        int tem1 = (A*A*A+A*A) % mod; // 4.第一步先进行G(i)操作还是F(i)操作
        int tem2 = (A*A*A-A*A) % mod;
        number = min(GF[tem1][B], GF[tem2][B])+1; //选择较小的那个。
        if(number>=inf) {printf("%d\n", -1);}
        else
        {
            printf("%lld\n", number);
        }

    }
    return 0;
}
