# 题目: 用两个栈实现队列
## 题目描述：
用两个栈来实现一个队列，完成队列的Push和Pop操作。 队列中的元素为int类型。理解题意就是利用两个先进后出的栈实现一个先进先出的队列
# 本题考点：
  
  数据结构栈的编程能力
  
# 解题思路:
   理解题意后是要用两个“先进后出”的栈实现一个“先进先出”的队列，先将元素填进stack1，stack1.push(node)，然后stack2为空，但stack1不为空，就将stack1的元素弹出，再压入栈2，这样先进的元素就在栈2顶，这样就实现了先进先出。就是先进后出+后进先出=先进先出。
# 代码

[C++](./QueueWithTwoStacks.cpp)

[Python](./QueueWithTwoStacks.py)

# C++: 
### 
```c++
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
    def pop(self):
        # return xx
        l1 = len(self.stack1)
        l2 = len(self.stack2)
        if l2==0:
            while l1!=0:
                temp = self.stack1.pop()
                self.stack2.append(temp)
                l1 = len(self.stack1)
        res = self.stack2.pop()
        return res
```
## 参考
  -  [C++ stl容器stack栈pop用法](https://blog.csdn.net/l494926429/article/details/52066918)
  -  [Python list pop()用法](https://www.runoob.com/python/att-list-pop.html)
  -  [Python栈实现](https://www.jianshu.com/p/1327cc0de255)
