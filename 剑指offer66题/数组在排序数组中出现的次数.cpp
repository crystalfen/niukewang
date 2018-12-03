class Solution {
public:
    int GetNumberOfK(vector<int> data ,int k) {
        //并没有说是升序还是降序
        //先从左到右，找第一个等于k的值，再往后找到不等于k的值
        int left = 0;
        while(left < data.size() && data[left] != k)
        {
            left++;
        }
        if(left==data.size()) return 0; //没找到
        int right = left;//第一个等于k的值的下标
        while(right < data.size() && data[right] == k)
        {
            right++;
        }
        return right-left;

    }
};
