class Solution {
public:
    int findComplement(int num) {
        int mask = ~0;
        int n = num;
        while(num != 0) {
            mask = mask << 1;
            num = num >> 1;
        }
        return ~mask ^ n;
    }
};