class Solution {
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        //�Ƚ������С���������£�Ȼ���������ǰk����

        vector<int> results;
        if(k>input.size()) return results;
        sort(input.begin(),input.end());
        for(int i = 0; i < k; i++)
            results.push_back(input[i]);
        return results;

    }
};
