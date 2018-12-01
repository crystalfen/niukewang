class Solution {
public:
    bool Find(int target, vector<vector<int>> array) {
        //À„∑®∏¥‘”∂»O(M+N),  M = array.size();int N = array[0].size();
        if(array.size()<1)
            return false;
        if(array[0].size()<1)
            return false ;
        int r = array.size() - 1;
        int j = 0;
        while(r >= 0 && j <= array[0].size()-1)
        {
            if(array[r][j] == target)
            {
                return true;
            }
            else if(array[r][j]>target)
            {
                r--;
            }
            else
            {
                j++;
            }
        }
        return false;
    }
};
