#include<iostream>
#include <cstdio>
#include<cstring>
using namespace std;
long long vowel[5001][51]; //vowel[i][j]代表总共有i个数字时，最后面有j个连续的元音
long long consonant[5001][51]; // //consonant[i][j]代表总共有i个数字时，最后面有j个连续的辅音
const int  mod = 1e9+7;

int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int N, A, B;
        scanf("%d%d%d",&N,&A,&B);
        long long ans = 0;
        memset(vowel, 0, sizeof(vowel));
        memset(consonant, 0, sizeof(consonant));
        vowel[1][1] = 5;
        consonant[1][1] = 21;
        for(int i = 2 ; i <= N; i++)
        {
            int j = 2;
            for(; j<=N && j<= A; j++)
            {
                vowel[i][j] = (vowel[i-1][j-1] * 5) % mod;
                consonant[i][1] = (consonant[i][1]+vowel[i-1][j-1]*21) % mod;
            }
            consonant[i][1] = (consonant[i][1]+vowel[i-1][j-1]*21) % mod;
            for(j = 2; j<=N && j<=B; j++)
            {
                consonant[i][j] = ( consonant[i-1][j-1] * 21) % mod;
                vowel[i][1] = (vowel[i][1] + consonant[i-1][j-1]*5)%mod;
            }
            vowel[i][1] = (vowel[i][1] + consonant[i-1][j-1]*5)% mod;
        }

        for(int i = 1; i <= N; i++)
        {
            for(int j = 1; j <= A; j++)
                ans = (ans+vowel[i][j])% mod;
            for(int j = 1; j<=B; j++)
                ans = (ans+consonant[i][j]) % mod;
        }
        printf("%lld\n",ans);
    }

    return 0;
}
