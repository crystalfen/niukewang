class Solution {
public:
    int minNumberInRotateArray(vector<int> rotateArray) {
        //1.顺序查找，最好的情况下O(1),最坏的情况下O(n)
        /*
        int len = rotateArray.size();
        if(len<1) return 0;
        //if(len==1) return rotateArray[0];
        int i = 0;
        while(i+1<len && rotateArray[i+1]>=rotateArray[i])
        {
            i++;
        }
        if(i+1==len) return rotateArray[0]; //没有旋转，返回最后一个元素
        //else if(i==0) return
        else
            return rotateArray[i+1];
        */

        //2. 二分法查找 O(log(n))
        int len = rotateArray.size();
        if(len<1) return 0;
        int left = 0;
        int right = len - 1;
        if(left==right || rotateArray[left] < rotateArray[right]) //长度为1或未翻转
            return rotateArray[0];
        while((left+1)<right)
        {
            int mid = (left + right) / 2;
            //if(mid==left || mid == right) break;
            if(rotateArray[mid] > rotateArray[right]) //向右找
                left = mid;
            else if(rotateArray[mid] <= rotateArray[right])
                right = mid;
        }
        return rotateArray[right];

    }
};
