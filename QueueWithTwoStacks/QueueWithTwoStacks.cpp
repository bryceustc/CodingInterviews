class Solution
{
public:
    void push(int node) {
        stack1.push(node);
    }

    int pop() {
        int temp = 0;
        if (stack2.empty())
        {
            while(!stack1.empty())
            {
                temp = stack1.top();
                stack1.pop();
                stack2.push(temp);
            }
        }
        int res = stack2.top();
        stack2.pop();
        return res;
    }

private:
    stack<int> stack1;
    stack<int> stack2;
};
