class Solution {
public:
    double Power(double base, int exponent) {
       //x��n�η�ʽx�����Լ�n��
        double result = 1.0;
        if(exponent==0) return result;
        else if(exponent>0)
        {
            for(int i = 1; i <= exponent; i++)
                result = result * base;
        }
        else
        {
             for(int i = 1; i <= -exponent; i++)
                result = result / base;
        }
        return result;
    }
};
