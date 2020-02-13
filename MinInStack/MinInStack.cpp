class Solution {
public:
    void push(int value) {
        stack1.push(value);
        if (stack2.empty() || value < stack2.top())
        {
            stack2.push(value);
        }
        else
        {
            int t = stack2.top();
            stack2.push(t);
        }
    }
    void pop() {
        stack1.pop();
        stack2.pop();
    }
    int top() {
        int a = stack1.top();
        return a;
    }
    int min() {
        int b = stack2.top();
        return b;
    }
private:
    stack<int> stack1;
    stack<int> stack2;
};
