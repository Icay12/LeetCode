class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        int len = A.size();
        if(len < 3)
            return 0;
        vector<int> gap(len, 0);
        
        for(int i = 0; i < len - 1; ++i) {
            gap[i] = A[i+1] - A[i];
        }
        
        int res = 0;
        int l = 0; int r = 1;
        while(r < len && l < len) {
            while(r < len-1 && gap[r] == gap[l])
                ++r;
            while(l < r) {
                if(r - l >= 2)
                    res += (r - l - 1);
                ++l;
            }
            r += 1;
        }
        return res;
    }
};