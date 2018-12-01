class Solution {
public:
    void reOrderArray(vector<int> &array) {
        // 1. 最简单的方法：先新建两数组分别存放奇数，偶数，再拼接
        /*vector<int> odd;
        vector<int> even;
        for(int i = 0 ; i < array.size(); i++)
        {
            if(array[i] % 2 == 0)
                even.push_back(array[i]);
            else
                odd.push_back(array[i]);
        }
        for(int j = 0; j<even.size(); j++)
            odd.push_back(even[j]);
        for(int i = 0; i< array.size(); i++)
            array[i] = odd[i];
        return;*/

        //2. 从前往后查找，是奇数不变，是偶数，就往后找，找到奇数，把该奇数插到前面。
        for(int i = 0; i< array.size(); i++)
        {
            if(array[i] % 2 == 0)
            {
                int j = i + 1;
                while(j<array.size() && array[j] % 2 == 0)
                {
                    j++;
                }
                if(j==array.size()) return;
                int val = array[j];
                for(int k = j; k > i; k--)
                    array[k] = array[k-1];
                array[i] = val;
            }

        }
    }
};
