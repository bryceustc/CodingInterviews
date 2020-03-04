class Solution:
    def __init__(self):
        self.res = []
    def printNumbers(self, n: int) -> List[int]:
        self.res = []
        if n<=0:
            return self.res
        numer = ['0' for _ in range(n)]
        self.helper(0, n, numer)
        return self.res;
    def helper(self, index, n, numer):
        if index == n:
            self.saveNumber(numer)
            return
        for i in range(10):
            numer[index] = str(i)
            self.helper(index+1, n, numer)
    def saveNumber(self, numer):
        index = 0
        s = ""
        while (index<len(numer)):
            if (numer[index]!='0'):
                break
            index+=1
        while (index<len(numer)):
            s+=numer[index]
            index+=1
        if s:
            num = int(s)
            self.res.append(num)
