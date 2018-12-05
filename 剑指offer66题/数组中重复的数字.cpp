class Solution {
public:
    // Parameters:
    //        numbers:     an array of integers
    //        length:      the length of array numbers
    //        duplication: (Output) the duplicated number in the array number
    // Return value:       true if the input is valid, and there are some duplications in the array number
    //                     otherwise false
    bool duplicate(int numbers[], int length, int* duplication) {
        // ·¨Ò»£ºmap
        unordered_map<int,int> map1;
        for(int i = 0; i < length; i++)
        {
            map1[numbers[i]]++;
            if(map1[numbers[i]]>1)
            {
                duplication[0] = numbers[i];
                return true;
            }
        }
        return false;

    }
};
