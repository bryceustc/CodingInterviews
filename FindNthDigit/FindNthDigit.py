class Solution:
    def findNthDigit(self, n: int) -> int:
        if n<0:
            return -1
        if n<10:
            return n
        digits = 1
        numbers = 9
        while n>digits*numbers:
            n-=digits*numbers
            digits+=1
            numbers*=10
        n-=1
        a = n//digits
        b = n%digits
        num = int(pow(10,digits-1) + a)
        idx = digits-b
        for i in range(1, idx):
            num//=10
        return num%10
        # s = str(num)
        # res = int(s[b])
        # return res
