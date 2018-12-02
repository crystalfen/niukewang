class Solution
{
public:
    bool IsPopOrder(vector<int> pushV,vector<int> popV)
    {
        //外循环：popV从左到右遍历，j;
        //内循环：pushV从左到右遍历i，当popV[j]元素不等于栈顶元素（栈不为空）或者栈为空时，且pushV[i]不等于popV[j]一直入栈。
        /* int i = 0;
           stack<int> s;
           if(pushV.size()!=popV.size()) return false;
           for(int j = 0; j < popV.size(); j++)
           {
               while(i<pushV.size() && pushV[i] != popV[j] &&(s.empty() || (!s.empty() && popV[j] != s.top())))
               {
                   s.push(pushV[i]);
                   i++;
               }
               if(pushV[i]==popV[j])
               {
                   i++;
               }
               if(!s.empty() && popV[j] == s.top()) s.pop();
               if(i==pushV.size()) //pushV数组已经遍历完了
               {
                   //判断栈是否为空，如果不为空，就看出栈顺序是否和剩下未遍历的popV数组一样，不一样返回false
                   while(!s.empty())
                   {
                       if(s.top() != popV[j+1]) return false;
                       s.pop();
                       j++;
                   }
               }
           }
           return true;
           */
        //pushV入栈，与popV相等就出栈。最后如果栈为空，就返回true;
        if(pushV.size() == 0) return false;
        stack<int> s;
        for(int i = 0,j=0; i < pushV.size(); i++)
        {
            s.push(pushV[i]);
            while(j<popV.size() && popV[j]==s.top())
            {
                s.pop();
                j++;
            }
        }
        return s.empty();
    }
};
