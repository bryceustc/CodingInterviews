// Solution 1:
class Solution {
public:
    int NumberOf1Between1AndN_Solution(int n)
    {
        int res = 0;
        if (n<1)
            return res;
        for (int i=1;i<=n;i++)
        {
            res += NumberOf1(i);
        }
        return res;
    }
    int NumberOf1(int n)
    {
        int num = 0;
        while (n)
        {
            if(n%10==1)
                num++;
            n /= 10;
        }
        return num;
    }
};

// Solution 2:
class Solution {
public:
    int NumberOf1Between1AndN_Solution(int n)
    {
        // 统计次数
        int res = 0;
        //i表示当前分析的是哪一个数位
        for (long int i= 1; i<=n; i*=10)
        {
            // 分别以个位、十位、百位...分隔数字，然后统计1出现的次数
            long int a = n/i;
            long int b = n%i;
            // 以百位为例，如果百位数字>=2，n=31456为例，a=314,b=56,百位为4>=2，
            // 则总共有0~31个百位为1的，也就是（a/10+1）*100=3200个百位为1的数字，同理从个位统计到最高位再相加。
            // 如果百位为1，n=31156为例，a=311,b=56，百位1==1
            // 则总共最高两位有0~30开头且百位为1的，100~199共100个,所以（a/10）* 100 = 3100 再加上31开头百位为1的（b+1）=57个1
            // 如果百位为0，以n=31056为例，a=310,b=56,百位0==0
            // 则总共最高两位有0~30开头且百位为1的，所以（a/10）* 100 = 3100，31开头没有百位为1的，所以不加
            // 综上：三种情况，可以用（a+8）/10来表示，因为只有>=2时+8才等价于（a/10+1）
            // 而b的数字，要结合a%10取a的最低位，也就是实际数字相应的位数，就是对应个位、十位、百位...判断是否为1，在进行相加
            res += (a+8)/10*i + (a%10==1)*(b+1);
        }
        return res;
    }
};
