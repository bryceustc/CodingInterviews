# 题目: 包含min函数的栈
## 题目描述：
定义栈的数据结构，请在该类型中实现一个能够得到栈的最小元素的 min 函数在该栈中，调用 min、push 及 pop 的时间复杂度都是 O(1)。
# 本题考点：
  
  数据结构栈的编程能力
  
# 解题思路:
  此题与LeetCode-155题一样

   理解题意后是要用一个数据栈压入元素，另一个为辅助栈存储最小元素。
   举个例子：

  入栈的时候：首先往空的数据栈里压入数字3，显然现在3是最小值，我们也把最小值压入辅助栈。接下来往数据栈里压入数字4。由于4大于之前的最小值，因此我们只要入数据栈，不压入辅助栈。

  出栈的时候：数据栈和辅助栈都出栈

  获得栈顶元素的时候：直接返回数据栈的栈顶元素。

  栈最小元素：直接返回辅助栈的栈顶元素。
# 代码

[C++](./MinInStack.cpp)

[Python](./MinInStack.py)

# C++: 
### 
```c++
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
```

# Python:
### 
```python
# -*- coding:utf-8 -*-
class Solution:
    def __init__(self):
        self.stack1 = []
        self.stack2 = []
    def push(self, node):
        # write code here
        self.stack1.append(node)
        if len(self.stack2)==0 or node < self.stack2[-1]:
            self.stack2.append(node)
        else:
            temp = self.stack2[-1]
            self.stack2.append(temp)
    def pop(self):
        # write code here
        self.stack1.pop()
        self.stack2.pop()
    def top(self):
        # write code here
        return self.stack1[-1]
    def min(self):
        # write code here
        return self.stack2[-1]
```
## 参考
  -  [C++类成员的访问范围（C++ private、public、protected）](http://c.biancheng.net/view/219.html)
  -  [LeetCode-155题-最小栈](https://github.com/bryceustc/LeetCode_Note/blob/master/cpp/Min-Stack/README.md)
  -  [Python栈实现](https://www.jianshu.com/p/1327cc0de255)

