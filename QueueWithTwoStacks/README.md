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

## C++: 
```c++
class MyQueue {
public:
    MyQueue() {

    }

    void push(int x) {
        s1.push(x);
    }

    int pop() {
        int res = this->peek();
        s2.pop();
        return res;
    }

    int peek() {
        // 注意要加这个判断，因为有可能先加进去3个元素，只弹出一个
        // 后边再加元素，剩下的两个元素优先级还是最高
        if (s2.empty()) {
            while(!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }
        if (!s2.empty()) return s2.top();
        return -1;
    }

    bool empty() {
        return s1.empty() && s2.empty();
    }
private:
    stack<int> s1;
    stack<int> s2;
};
```

## Python:
```python
# -*- coding:utf-8 -*-
class MyQueue:

    def __init__(self):
        self.s1, self.s2 = [], []

    def push(self, x: int) -> None:
        self.s1.append(x)

    def pop(self) -> int:
        peek = self.peek()
        self.s2.pop()
        return peek

    def peek(self) -> int:
        if not self.s2: 
            while self.s1:
                self.s2.append(self.s1.pop())
        if self.s2:
            return self.s2[-1]
        return -1

    def empty(self) -> bool:
        return (not self.s1) and (not self.s2)

```
## 参考
  -  [C++ stl容器stack栈pop用法](https://blog.csdn.net/l494926429/article/details/52066918)
  -  [Python list pop()用法](https://www.runoob.com/python/att-list-pop.html)
  -  [Python栈实现](https://www.jianshu.com/p/1327cc0de255)
