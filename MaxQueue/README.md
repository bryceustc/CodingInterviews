# 题目:队列的最大值

## 题目描述：
请定义一个队列并实现函数 max_value 得到队列里的最大值，要求函数max_value、push_back 和 pop_front 的时间复杂度都是O(1)。

若队列为空，pop_front 和 max_value 需要返回 -1
  
  **示例：**
  ```
输入: 
["MaxQueue","push_back","push_back","max_value","pop_front","max_value"]
[[],[1],[2],[],[],[]]
输出: [null,null,null,2,1,2]
  ```
  
# 解题思路:
用一个队列，一个双端队列来实现

用一个队列保存正常元素，另一个双向队列保存单调递减的元素

入栈时，第一个队列正常入栈；第二个队列是递减队列，所以需要与之前的比较，从尾部把小于当前value的全部删除（因为用不到了）

出栈时，第一个队列正常出栈；第二个队列的头部与出栈的值作比较，如果相同，那么一起出栈

# 时间复杂度：
O(1)
# 空间复杂度
 O(n)
# 代码

[C++](./MaxQueue.cpp)

[Python](./MaxQueue.py)

# C++: 
###  
```c++
class MaxQueue {
public:
    queue<int> q1;
    deque<int> q2;
    MaxQueue() {

    }
    
    int max_value() {
        int res = -1;
        if (!q2.empty())
        {
            res = q2.front();
        }
        return res;
    }
    
    void push_back(int value) {
        q1.push(value);
        while (!q2.empty() && q2.back()<value)
        {
            q2.pop_back();
        }
        q2.push_back(value);
    }
    
    int pop_front() {
        int res = -1;
        if (q1.empty()) return res;
        res = q1.front();
        if (res == q2.front())
        {
            q2.pop_front();
        }
        q1.pop();
        return res;
    }
};

/**
 * Your MaxQueue object will be instantiated and called as such:
 * MaxQueue* obj = new MaxQueue();
 * int param_1 = obj->max_value();
 * obj->push_back(value);
 * int param_3 = obj->pop_front();
 */
```
# Python:
###  
```python
class MaxQueue:

    def __init__(self):
        self.queue=[]
        self.max_queue=[]
        
    def max_value(self) -> int:
        if not self.queue:
            return -1
        return self.max_queue[0]
        

    def push_back(self, value: int) -> None:
        self.queue.append(value)
        while self.max_queue and value > self.max_queue[-1]:
                self.max_queue.pop(-1)
        self.max_queue.append(value)

    def pop_front(self) -> int:
        if not self.queue:
            return -1
        if self.queue[0]==self.max_queue[0]:
            self.max_queue.pop(0)
        return self.queue.pop(0)



# Your MaxQueue object will be instantiated and called as such:
# obj = MaxQueue()
# param_1 = obj.max_value()
# obj.push_back(value)
# param_3 = obj.pop_front()
```



