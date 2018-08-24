class Solution {
public:
    // x + (x+1) + (x+2) +...+(x+k-1) = N
    //
    int consecutiveNumbersSum(int N) {
        int res = 1;
        for(int k = 2; k*(k-1) < N*2; ++k ) {
            if( (N - k*(k-1)/2) % k == 0)
                res++;
        }
        return res;
    }
};