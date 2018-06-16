class Solution {
public:
    int hammingWeight(uint32_t n) {
        int cnt = 0;
        while(n != 0) {
            n &= (n-1);
            cnt++;
        }
        return cnt;
    }
};

class Solution {
public:
    int hammingWeight(uint32_t n) {
        uint32_t cnt = n;
        cnt = (cnt & 0x55555555) + ((cnt >> 1) & 0x55555555);
        cnt = (cnt & 0x33333333) + ((cnt >> 2) & 0x33333333);
        cnt = (cnt & 0x0f0f0f0f) + ((cnt >> 4) & 0x0f0f0f0f);
        cnt = (cnt & 0x00ff00ff) + ((cnt >> 8) & 0x00ff00ff);
        cnt = (cnt & 0x0000ffff) + ((cnt >> 16) & 0x0000ffff);
        return cnt;
        
    }
};