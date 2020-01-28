class Solution {
public:
    // 数字的格式可以用A[.[B]][e|EC]或者.B[e|EC]表示，
    // 其中A和C都是整数（可以有正负号，也可以没有）
    // 而B是一个无符号整数
    bool isNumeric(char* str)
    {
        // 非法输入处理
        if (*str == '\0')
            return false;
        // 标记符号、小数点、e是否出现过
        bool sign = false, decimal = false, hasE = false;
        int n = strlen(str);
        for (int i=0;i<n;i++)
        {
            if (str[i]=='e' || str[i] == 'E')
            {
                if (i == n-1)  return false; // e后面一定要接数字
                if (hasE)  return false; // 不能同时存在两个e
                hasE = true;
            }
            else if (str[i] == '+' || str[i]=='-')
            {
                if (sign && str[i-1]!='e' && str[i-1]!= 'E') // 第二次符号出现必须接在e之后
                    return false;
                if (!sign && i>0 && str[i-1]!='e' && str[i-1]!='E') // 第一次出现'+''-'符号且不在字符串开头 则必须出现在e之后
                    return false;
                sign = true;
            }
            else if (str[i]=='.')
            {
                if (hasE || decimal)
                    return false;
                decimal = true;
            }
            else if (str[i]<'0'||str[i]>'9')
                return false;
        }
        return true;
    }
};
