class Solution {
public:
    double myPow(double x, int n) {
        if(n == 0) {
            return 1;
        }
        if(n < 0) {
            x = 1.0/x;
            if(n == INT_MIN) {
                n = (n + 1) * -1;
                return x * myPow(x, n);
            }
            n = -n; // be careful when n = INT_MIN
            return myPow(x, n);
        }
        if(n % 2 == 0) {
            return myPow(x * x, n / 2);
        }
        else {
            return x * myPow(x * x, n / 2);
        }
    }
};