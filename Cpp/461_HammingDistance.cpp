class Solution {
public:
    int hammingDistance(int x, int y) {
        int n = x ^ y;
        int res = 0;
        //check 1 in n
        while(n != 0) {
            n = n & (n-1);
            res++;
        }
        return res;
    }
};