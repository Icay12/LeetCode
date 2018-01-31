class Solution {
public:
    int climbStairs(int n) {
        if(n == 0 || n == 1 || n == 2)
            return n;
        int step1 = 1, step2 = 2;
        int step;
        for(int i = 3; i <= n; ++i) {
            step = step1 + step2;
            step1 = step2;
            step2 = step;
        }
        return step;
    }
};