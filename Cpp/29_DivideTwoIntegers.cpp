class Solution {
public:
    int divide(int dividend, int divisor) {
        if(divisor == 0 || dividend == INT_MIN && divisor == -1) {
            return INT_MAX;
        }
        int sign = 1;
        if((dividend < 0 && divisor > 0) || (dividend > 0 && divisor < 0)) {
            sign = -1;
        }
        long long absDividend = labs(dividend); //use labs&long long,  INT_MIN is bigger than INT_MAX
        long long absDivisor = labs(divisor);
        int result = 0;
        while(absDividend >= absDivisor) {
            //use left shift to save time
            long long tmp = absDivisor;
            long long mul = 1;
            while(absDividend >= (tmp << 1)) {
                tmp = tmp << 1;
                mul = mul << 1;
            }
            absDividend -= tmp;
            result += mul;
        }
        result = sign == 1 ? result : -result;
        return result;
    }
};