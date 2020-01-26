# 题目:正则表达式匹配
## 题目描述：
请实现一个函数用来匹配包括’.’和’\*‘的正则表达式。模式中的字符’.’表示任意一个字符，而’\*‘表示它前面的字符可以出现任意次（包含0次）。 在本题中，匹配是指字符串的所有字符匹配整个模式。例如，字符串”aaa”与模式”a.a”和”abaca”匹配，但是与”aa.a”和”ab\*a”均不匹配
# 本题考点：
  
  数学思维能力
  
# 解题思路:
  
  1.) 直接法。最直观的做法是从头到尾扫描字符串，每一次碰到空格字符的时候做替换。由于是把1个字符替换成3个字符，我们必须要把空格后面所有的字符都后移两个字节，否则就有两个字符被覆盖了。下图展示了从前往后把字符串中的空格替换成'%20'的过程：
  
  ![2](https://github.com/bryceustc/CodingInterviews/blob/master/ReplaceSpaces/Images/2.jpg)
  
  假设字符串的长度是n。对每个空格字符，需要移动后面O(n)个字符，因此对含有O(n)个空格字符的字符串而言总的时间效率是O(n<sup>2</sup>),所以时间复杂度:O(n<sup>2</sup>),空间复杂度:O(n)

  2.) Step1.先遍历一次字符串，这样就能统计出字符串中空格的总数，并可以由此计算出替换之后的字符串的总长度。

　　以前面的字符串"We arehappy."为例，"We are happy."这个字符串的长度是14（包括结尾符号'\0'），里面有两个空格，因此替换之后字符串的长度是18。
  
  Step2.从字符串的后面开始复制和替换。

　　准备两个指针，P1和P2。P1指向原始字符串的末尾，而P2指向替换之后的字符串的末尾。接下来向前移动指针P1，逐个把它指向的字符复制到P2指向的位置，直到碰到第一个空格为止。接着向前复制，直到碰到第二、三或第n个空格。
  ![3](https://github.com/bryceustc/CodingInterviews/blob/master/ReplaceSpaces/Images/3.jpg)
  
 从上面的分析我们可以看出，所有的字符都只复制（移动）一次，因此这个算法的时间效率是O(n)，比第一个思路要快。
 
 时间复杂度为O(n)，空间复杂度为O(n)
# 代码

[C++](./RegularExpressionsMatching.cpp)

[Python](./RegularExpressionsMatching.py)

# C++: 
### 方法一：模拟直接法
```c++
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
	void replaceSpace(char *str,int length) {
        if (str == NULL || length <=0)
            return;
        for (int i=0;i<length;i++)
        {
            if (*(str+i)==' ')
            {
                length+=2;//长度+2
                for (int j=length;j>i+2;j--)
                {
                    *(str+j)=*(str+j-2);
                }
                *(str+i) = '/%';
                *(str+i+1) = '2';
                *(str+i+2) = '0';
            }
        }
	}
};

int main()
{
    char str[] = "we are happy.";
    int length = 12;
    Solution().replaceSpace(str,length);
    cout<< str<<endl;
    system("pause");
    return 0;
}

```
### 方法二：双指针法，先计算空格的个数，然后计算新字符串的长度，再从后向前进行替换，时间复杂度O(n);
```c++
class Solution {
public:
	void replaceSpace(char *str,int length) {
        if (str == NULL || length <=0)
            return;
        int i=0;
        int oldLength = 0; // 原字符串长度
        int newLength = 0; // 替换后字符串长度
        int numberofBlank = 0; //空格数量
        while(str[i]!='\0')
        {
            oldLength++;
            if (str[i]==' ')
            {
                numberofBlank++;
            }
            i++;
        }
        newLength = oldLength + numberofBlank*2; // 计算替换后字符串的长度
        if (newLength > length)  // 如果大于最大长度直接返回 因为无法插入
            return;
        // 设置两个指针，一个指向原始字符串的末尾，另一个指向替换之后的字符串的末尾 注意不要减一
        int p = oldLength; //设置p指针指向旧字符串的末尾
        int q = newLength; //设置q指针指向新字符串的末尾
        while (p>=0 && p<q)
        {
            if (str[p]==' ')
            {
                str[q--] = '0';
                str[q--] = '2';
                str[q--] = '/%';
            }
            else
            {
                str[q--] = str[p];
            }
            p--;
        }
	}
};
```
# Python:
### 方法一：replace 函数操作
```python
# -*- coding:utf-8 -*-
class Solution:
    # s 源字符串
    def replaceSpace(self, s):
        # write code here
        s = s.replace(' ','%20')
        return s
```
### 方法二：join方法
```python
# -*- coding:utf-8 -*-
class Solution:
    # s 源字符串
    def replaceSpace(self, s):
        # write code here
        s = list(s)
        count = len(s)
        for i in range(0,count):
            if s[i] == ' ':
                s[i] = '%20'
        return ''.join(s)
```

