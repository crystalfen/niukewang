class Solution {
public:
    vector<int> FindNumbersWithSum(vector<int> array,int sum) {
        //注意是递增序列，left+right,小于sum时，left++;大于sum时，right--
        //定义一个一个最小乘积。
        //复杂度O(N)
        vector<int> res;
        int min = INT_MAX;
        if(array.size()<=1) return res;
        int left = 0;
        int right = array.size()-1;
        int minleft=0, minright=0;
        while(left<=right)
        {
            if(array[left]+array[right] < sum)
                left++;
            else if(array[left]+array[right] > sum)
                right--;
            else
            {
                if(array[left]*array[right] < min)
                {
                    min = array[left] * array[right];
                    minleft = left;
                    minright = right;
                }
                left++;
                right--;
            }
        }
        if(minright!=0)
        {
            res.push_back(array[minleft]);
            res.push_back(array[minright]);
        }
        return res;

    }
};
