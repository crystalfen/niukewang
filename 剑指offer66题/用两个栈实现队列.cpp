class Solution
{
public:
    //push比较简单，主要是pop,可以先让栈1的元素全部出栈到栈二，栈二pop,再将栈二的元素全部出栈到栈1
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
