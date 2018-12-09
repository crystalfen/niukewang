class Solution {
public:
    vector<int> arr;
    void Insert(int num)
    {
       arr.push_back(num);
    }

    double GetMedian()
    {
      sort(arr.begin(), arr.end());
      double val;
      int len = arr.size();
      if(len%2==1)
          val = double(arr[len/2]);
      else
      {
          val=double(arr[len/2]+arr[len/2-1])/2;
      }
      return val;
    }

};
