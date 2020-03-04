class Solution {
public:
    vector<int> res;
    vector<int> printNumbers(int n) {
        if (n<=0) return res;
        //创建一个能容纳最大值的字符数组 初始全部设置为0
        string number(n+1, '0');
        while(!Increment(number))
        {
            saveNumber(number);
        }
        return res;
    }
    bool Increment(string &number)
    {
        int carry = 0;
        int m = number.size();
        for (int i=m- 1; i>=0;i--)
        {
            int temp = number[i] - '0' + carry;
            if (i==m-1)
            {
                temp++;
            }
            carry  = temp/10;
            temp %=10;
            number[i] = temp+ '0';
        }
        return number[0]=='1';// 判断是否溢出
    }
    void saveNumber (string number) //由于此处输出，不需要修改number，因此不需要加引用
    {
        string s = "";
        int index = 0;
        // 找到第一不为'0'的位数
        for (;index<number.size();index++)
        {
            if (number[index]!='0')
            {
                break;
            }
        }
        // 拼接成一个完整数字
        for (; index<number.size();index++)
        {
            s+=number[index];
        }
        // 转为整数存入结果
        int num = stoi(s);
        res.push_back(num);
    }
};
