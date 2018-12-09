class Solution {
public:
    int LastRemaining_Solution(int n, int m)
    {
        vector<int> arr;
        for(int i = 0; i<n;i++)
            arr.push_back(i);
        int j = 0;
        if(arr.size()==0) return -1;//没有学生的时候
        while(arr.size()>1)
        {
            vector<int>::iterator it = arr.begin();

            for(;it!=arr.end();)
            {
                if(j==m-1)
                {
                    arr.erase(it);//删除该元素，同属it++
                    j = 0;
                }
                else
                {
                    it++;
                    j++;
                }
            }

        }
        return arr[0];
    }
};
