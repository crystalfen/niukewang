class Solution
{
public:
    int Fibonacci(int n)
    {
        /*递归法时间太长
         if(n<2)
             return n<=0? 0 : 1;
        return Fibonacci(n-1) + Fibonacci(n-2);
        */
        //循环
        /*if(n<2)
            return n<=0? 0 : 1;
        vector<int>Fib(n+1);
        Fib[0] = 0;
        Fib[1] = 1;
        for(int i = 2; i <= n; i++)
            Fib[i] = Fib[i-1] + Fib[i-2];
        return Fib[n];*/
        //动态规划？
        if(n<2)
            return n<=0? 0 : 1;
        int f = 0; //f代表第0，2，4，6，8，。。的值
        int g = 1; //g代表第1，3，5，7，。。的值
        int num = n / 2;
        int re = n % 2;
        while(num--)
        {
            f = f + g;
            g = g + f;
        }
        return re==0 ? f : g;
    }
};
