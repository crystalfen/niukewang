class Solution {
public:
    vector<int> maxInWindows(const vector<int>& num, unsigned int size)
    {
        vector<int> res;
        if(size==0) return res;
        for(int i = 0; i + size <= num.size(); i++)
        {
            int max = num[i];
            for(unsigned int j = 1; j<size;j++)
            {
                if(max<num[i+j])
                    max = num[i+j];
            }
            res.push_back(max);
        }
        return res;
    }
};
