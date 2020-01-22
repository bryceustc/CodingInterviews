// C++　Solution 1:
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


// C++ Solution 2:
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
