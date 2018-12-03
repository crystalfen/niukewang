//对于题目中问题的回答：如果该负数前面的和加上该负数后仍是大于0，可以期望旁边的正数去弥补它。
//但是如果该负数前面的和加上该负数小于0，则不如重新从旁边的正数开始算。
class Solution {
public:
    int FindGreatestSumOfSubArray(vector<int> array) {
    //定义两个变量，一个记录最终的最大值，一个定义当前最大值。当当前最大值<0时，置0重新开始
        int Max = array[0];
        int curMax = array[0];
        //if(array.size()==1) return Max;
        for(int i = 1; i < array.size(); i++)
        {
           if(curMax<0) curMax = array[i];
           else
           {
               curMax += array[i];
           }
           Max = Max< curMax ? curMax : Max;
        }
        return Max;
    }
};
