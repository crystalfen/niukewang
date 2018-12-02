class Solution
{
public:
    bool IsPopOrder(vector<int> pushV,vector<int> popV)
    {
        //��ѭ����popV�����ұ�����j;
        //��ѭ����pushV�����ұ���i����popV[j]Ԫ�ز�����ջ��Ԫ�أ�ջ��Ϊ�գ�����ջΪ��ʱ����pushV[i]������popV[j]һֱ��ջ��
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
               if(i==pushV.size()) //pushV�����Ѿ���������
               {
                   //�ж�ջ�Ƿ�Ϊ�գ������Ϊ�գ��Ϳ���ջ˳���Ƿ��ʣ��δ������popV����һ������һ������false
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
        //pushV��ջ����popV��Ⱦͳ�ջ��������ջΪ�գ��ͷ���true;
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
