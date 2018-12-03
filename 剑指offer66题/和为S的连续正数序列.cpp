class Solution {
public:
    vector<vector<int> > FindContinuousSequence(int sum) {
        vector<vector<int>> res;
        int m = 2, a=1;
       // int n = (sum-a)/m;
        while((sum-a)/m>=1)
        {
            if((sum-a)%m==0)//如果能整除，说明从n到n+(m-1)个数满足条件
            {
               int n = (sum-a) / m;
               vector<int> arr;
               for(int i = n; i < n+m; i++)
               {
                   arr.push_back(i);
               }
               res.push_back(arr);
            }

            a += m;
            m++;

        }
        if(res.size()>=1)
            reverse(res.begin(), res.end());
        return res;


    }
};
