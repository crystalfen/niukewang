class Solution {
    int idex;
public:
    //����һ������ջ������ջ��Ԫ��С������
    stack<int> s1, s2;
    void push(int value) {
        s1.push(value);
        if(s2.empty()) //ֻ�е�ʱs2Ϊ�գ�������ջ��ֵС�ڵ���s2.top()ʱ��s2��Ҳ��ջ��
            s2.push(value);
        else if (s2.top()>=value)
            s2.push(value);
    }
    void pop() {
        if(s1.top()==s2.top())//���s1��ջ������Сֵ��s2Ҳ��ջ
            s2.pop();
        s1.pop();
    }
    int top() {
        return s1.top();
    }
    int min() {
        return s2.top();
    }
};
