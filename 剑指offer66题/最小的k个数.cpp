class Solution {
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        //先将数组从小到大排列下，然后依次输出前k个数

        vector<int> results;
        if(k>input.size()) return results;
        sort(input.begin(),input.end());
        for(int i = 0; i < k; i++)
            results.push_back(input[i]);
        return results;

    }
};
