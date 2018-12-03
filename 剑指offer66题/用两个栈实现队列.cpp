class Solution
{
public:
    //push�Ƚϼ򵥣���Ҫ��pop,��������ջ1��Ԫ��ȫ����ջ��ջ����ջ��pop,�ٽ�ջ����Ԫ��ȫ����ջ��ջ1
    void push(int node) {
        stack1.push(node);
    }

    int pop() {
        while(!stack1.empty())
        {
            stack2.push(stack1.top());
            stack1.pop();
        }
        int node = stack2.top();
        stack2.pop();
        while(!stack2.empty())
        {
            stack1.push(stack2.top());
            stack2.pop();
        }
        return node;
    }

private:
    stack<int> stack1;
    stack<int> stack2;
};
