// < 10 : 1
// < 100 : 1*10 + 10
// < 1000 : (1*10 + 10) * 10 + 100
class Solution {
public:
    int countDigitOne(int n) {
        long cnt = 0;
        for(long i = 1; i <= n; i= i*10) {
            long a = n / i;
            long b = n % i;
            cnt += (a+ 8)/10*i + (a % 10 == 1) * (b + 1);
        }
        return cnt;
    }
};