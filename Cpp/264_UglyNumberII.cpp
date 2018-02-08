class Solution {
public:
    int nthUglyNumber(int n) {
        int k2 = 0, k3 = 0, k5 = 0;
        vector<int> ugly(n, 1);
        ugly[0] = 1;
        for(int i = 1; i < n; ++i) {
            ugly[i] = min(ugly[k2]*2, min(ugly[k3]*3, ugly[k5]*5));
            if(ugly[i] == ugly[k2]*2)
                ++k2;
            if(ugly[i] == ugly[k3]*3)
                ++k3;
            if(ugly[i] == ugly[k5]*5)
                ++k5;
        }
        return ugly[n-1];
    }
};