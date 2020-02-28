class Solution {
public:
    int Add(int num1, int num2)
    {
        while(num2!=0)
        {
            int a = num1;
            num1 = num1^num2;
            num2 = (unsigned int)(a&num2)<<1;
        }
        return num1;
    }
};
