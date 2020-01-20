# 题目:替换空格
## 题目描述：
请实现一个函数，将一个字符串中的每个空格替换成“%20”。例如，当字符串为We Are Happy.则经过替换之后的字符串为We%20Are%20Happy。

在网络编程中，如果URL参数中含有特殊字符，如空格、'#'等，可能导致服务器端无法获得正确的参数值。我们需要将这些特殊符号转换成服务器可以识别的字符。转换的规则是在'%'后面跟上ASCII码的两位十六进制的表示。比如空格的ASCII码是32，即十六进制的0x20，因此空格被替换成"%20"。再比如'#'的ASCII码为35，即十六进制的0x23，它在URL中被替换为"%23"。
![1](https://github.com/bryceustc/CodingInterviews/blob/master/ReplaceSpaces/Images/1.jpg)
# 本题考点：
  
  数学思维能力
  
# 解题思路:
  
  1.) 直接法。最直观的做法是从头到尾扫描字符串，每一次碰到空格字符的时候做替换。由于是把1个字符替换成3个字符，我们必须要把空格后面所有的字符都后移两个字节，否则就有两个字符被覆盖了。下图展示了从前往后把字符串中的空格替换成'%20'的过程：
  
  ![2](https://github.com/bryceustc/CodingInterviews/blob/master/ReplaceSpaces/Images/2.jpg)
  
  假设字符串的长度是n。对每个空格字符，需要移动后面O(n)个字符，因此对含有O(n)个空格字符的字符串而言总的时间效率是O(n<sup>2</sup>),所以时间复杂度:O(n<sup>2</sup>),空间复杂度:O(n)

  2.) 上三角与下三角连乘，可以把B[i]=A[0]\*A[1]\*.....\*A[i-1]\*A[i+1]\*.....\*A[n-1]。看成A[0]\*A[1]\*.....\*A[i-1]和A[i+1]\*.....A[n-2\*A[n-1]两部分的乘积。
  
  即通过A[i]项将B[i]分为两部分的乘积。效果如下图所示
  ![image](https://github.com/bryceustc/CodingInterviews/blob/master/ConstuctArray/Image/image.png)
  
  不妨设定C[i]=A[0]\*A[1]\*...\*A[i-1]，D[i]=A[i+1]\*...\*A[n-2]\*A[n-1]。C[i]可以用自上而下的顺序计算出来，即C[i]=C[i-1]\*A[i-1]。类似的，D[i]可以用自下而上的顺序计算出来，即D[i]=D[i+1]\*A[i+1]。时间复杂度为O(n)，空间复杂度为O(n)
# 代码

[C++](./ReplaceSpaces.cpp)

[Python](./ReplaceSpaces.py)

# C++: 
### 方法一：模拟法
```c++
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> multiply(const vector<int>& A) {
        if (A.empty())
            return {};
        int n = A.size();
        vector<int> B (n,0);
        for (int i =0;i<n;i++)
        {
            int temp = 1;
            for (int j=0;j<n;j++)
            {
                if (j==i)
                    continue;
                temp *=A[j];
            }
            B[i] = temp;
        }
        return B;
    }
};

int main()
{
    vector<int> A = {0,1,2,3,4}; // n=5
    vector<int> B;
    B = Solution().multiply(A);
    for (int i=0;i<B.size();i++)
    {
        cout << B[i] << endl;
    }
    system("pause");
    return 0;
}
```
### 方法二：观察公式，上三角和下三角连乘
```c++
class Solution {
public:
    vector<int> multiply(const vector<int>& A) {
        if (A.empty())
            return {};
        int n = A.size();
        vector<int> B (n,0);
        //计算下三角连乘
        B[0]=1;
        for (int i=1;i<n;i++)
        {
            B[i] = B[i-1]*A[i-1];
        }
        // 计算上三角连乘
        int temp = 1;
        for (int i=n-2;i>=0;i--)
        {
            temp *= A[i+1];
            B[i] *= temp;
        }
        return B;
    }
};
```
# Python:
### 方法一：模拟法
```python
# -*- coding:utf-8 -*-
class Solution:
    def multiply(self, A):
        # write code here
        n = len(A)
        if n==0:
            return []
        B = [0 for _ in range(n)]
        for i in range(n):
            temp = 1
            for j in range(n):
                if j==i:
                    continue
                temp*=A[j]
            B[i] = temp
        return B
```
### 方法二：上/下三角法
```python
# -*- coding:utf-8 -*-
class Solution:
    def multiply(self, A):
        # write code here
        n = len(A)
        if n==0:
            return []
        B = [0 for _ in range(n)]
        ## 计算下三角
        B[0]=1
        for i in range(1,n):
            B[i]=B[i-1]*A[i-1]
        ## 计算上三角
        temp = 1
        for i in range(n-2,-1,-1):
            temp *= A[i+1]
            B[i] *= temp
        return B
```
### 方法三:使用Python reduce函数:
```python
# -*- coding:utf-8 -*-
class Solution:
    def multiply(self, A):
        # write code here
        B = []
        n = len(A)
        if n == 0:
            return B
        else:
            for i in range(n):
                ## 求B[i]，就把A[i]设为1，完了把A[i]值恢复
                temp = A[i]
                A[i] = 1
                B.append(reduce(lambda x,y:x*y, A))
                # reduce() 函数会对参数序列中元素进行累积。
                # 函数将一个数据集合（链表，元组等）中的所有数据进行下列操作：用传给 reduce 中的函数 
                # function（有两个参数）先对集合中的第 1、2 个元素进行操作，
                # 得到的结果再与第三个数据用 function 函数运算，最后得到一个结果。
                A[i] = temp
        return B
```
# 参考：
  - [Python reduce函数用法](https://www.runoob.com/python/python-func-reduce.html)

