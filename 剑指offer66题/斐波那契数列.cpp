class Solution
{
public:
    int Fibonacci(int n)
    {
        /*�ݹ鷨ʱ��̫��
         if(n<2)
             return n<=0? 0 : 1;
        return Fibonacci(n-1) + Fibonacci(n-2);
        */
        //ѭ��
        /*if(n<2)
            return n<=0? 0 : 1;
        vector<int>Fib(n+1);
        Fib[0] = 0;
        Fib[1] = 1;
        for(int i = 2; i <= n; i++)
            Fib[i] = Fib[i-1] + Fib[i-2];
        return Fib[n];*/
        //��̬�滮��
        if(n<2)
            return n<=0? 0 : 1;
        int f = 0; //f�����0��2��4��6��8��������ֵ
        int g = 1; //g�����1��3��5��7��������ֵ
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
