// Solution 1：
class Solution {
public:
    int StrToInt(string s) {
        long int res = 0;
        int n = s.size();
        int flag = 1;
        if (s.empty()||s[0]=='0') return res;
        if (s[0]=='-')
            flag = -1;
        for (int i=0;i<n;i++)
        {
            if (s[i]=='+'||s[i]=='-'&&i==0)
                continue;
            if (s[i]=='+'||s[i]=='-'&&i!=0)
                return 0;
            long int temp = s[i]-'0';
            if (temp>=0 && temp<=9)
                res = res*10+temp;
            else 
                return 0;
        }
        res *=flag;
        if (res > 2147483647 || res < -2147483648) res = 0;
        return res;
    }
};
// Solution 2:
class Solution {
public:
    int StrToInt(string str) {
        int res = 0;
        int n = str.size();
        int i=0;
        int flag = 1;
        // 去除空格和回车符号
        while(i<n&&(str[i]==' '||str[i]=='\t'))
        {
            i++;
        }
        //判断正负号
        if (str[i]=='-')
        {
            flag = -1;
            i++;
        }
        if (str[i]=='+')
        {
            if (flag==-1)
            {
                return 0;
            }
            i++;
        }
        for (int j = i;j<n;j++)
        {
            if (str[j]>='0'&&str[j]<='9')
            {
                int temp = str[j]-'0';
                if (res > 2147483647/10 || (res == 2147483647/10 && temp >7 && flag ==1) || (res == 2147483647/10 && temp >8 && flag ==-1))
                    return 0;
                按位运算
                res = (res << 1) + (res << 3) + (str[i] & 0xf);//res=res*10+str[i]-'0';
                // 字符'0'到'9'的ascii值的低4个二进制位刚好就是0到9所以str[i]&0xf等于str[i]-'0'
                res = res*10 + temp;
            }
            else
                return 0;
        }
        res *= flag;
        return res;
    }
};
// Solution 3:
class Solution {
public:
    enum Status{kValid = 0, kInValid};
    int g_nStatus = kValid;
    int StrToInt(string str) {
        g_nStatus = kInValid;
        long long num = 0;
        const char* cstr = str.c_str();
        // 判断是否为指针和是否为空字符串
        if(cstr != NULL && *cstr != '\0'){
            // 正负号标志位，默认是加号
            bool minus = false;
            if(*cstr == '+'){
                cstr++;
            }
            else if(*cstr == '-'){
                minus = true;
                cstr++;
            }
            if(*cstr != '\0'){
                num = StrToIntCore(cstr, minus);
            }
        }
        return (int)num;
    }
private:
    long long StrToIntCore(const char* cstr, bool minus){
        long long num = 0;
        while(*cstr != '\0'){
            // 判断是否是非法值
            if(*cstr >= '0' && *cstr <= '9'){
                int flag = minus ? -1 : 1;
                num = num * 10 + flag * (*cstr - '0');
                // 判断是否溢出,32位
                if((!minus && num > 0x7fffffff) || (minus && num < (signed int)0x80000000)){
                    num = 0;
                    break;
                }
                cstr++;
            }
            else{
                num = 0;
                break;
            }
        }
        // 判断是否正常结束
        if(*cstr == '\0'){
            g_nStatus = kValid;
        }
        return num;
    }
};
