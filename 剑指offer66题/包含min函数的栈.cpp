class Solution {
    int idex;
public:
    //定义一个辅助栈，辅助栈的元素小的在上
    stack<int> s1, s2;
    void push(int value) {
        s1.push(value);
        if(s2.empty()) //只有当时s2为空，或者入栈的值小于等于s2.top()时，s2才也入栈。
            s2.push(value);
        else if (s2.top()>=value)
            s2.push(value);
    }
    void pop() {
        if(s1.top()==s2.top())//如果s1出栈的是最小值，s2也出栈
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
