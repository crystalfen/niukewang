#include<iostream>
using namespace std;

int main()
{
    int number;
    cin>>number; //读入样例个数
    for(int i = 0; i < number; i++)
    {
        long long val;
        cin>>val;
        bool include1 = true; //将一个数分成两个数时，其中是否包含1.初始化为true,即包含1.
        if(val<= 3)
        {
            cout<<"NO"<<endl;
            continue;
        }
        while(val%2==0) //从4开始，有两种情况是二进制半整数的情况
        {
            val = val / 2;
            include1 = false; // 已经被2整除过，说明二进制半数都不是1。
        }
        if(val==1) //第一种情况：如果能被2一直整除直到等于1，即4,8,16,32，。。。这些数一定是二进制半整数。
        {
            cout<<"YES"<<endl;
            continue;
        }
        // 第二种情况，当不能再被2整除了也不等于1时。
        //如果是二进制半整数，说明较小的那个半整数被整除到了1，另一个数依然可以被2整除。即2*2*...*2*(1+2*2*...*2*1);
        val = val - 1;
        while(val % 2==0)
        {
            val = val / 2;
        }
        if(val==1 && !include1) // 满足第二种情况， 且不是1和另一个二进制整数组成。输出yes。否认,NO
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
