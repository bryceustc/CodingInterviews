# -*- coding:utf-8 -*-
class Solution:
    # s字符串
    def isNumeric(self, s):
        # write code here
        n = len(s)
        if n==0:
            return False
        sign = False
        decimal = False
        hasE = False
        for i in range(0,n):
            if s[i] == 'e' or s[i]=='E':
                if i == n-1:
                    return False
                if hasE:
                    return False
                hasE = True
            elif s[i]=='+' or s[i]=='-':
                if sign and s[i-1]!= 'e' and s[i-1] != 'E':
                    return False
                if not sign and i>0 and s[i-1] != 'e' and s[i-1]!='E':
                    return False
                sign = True
            elif s[i]=='.':
                if hasE or decimal:
                    return False
                decimal = True
            elif s[i]<'0' or s[i]>'9':
                return False
        return True
