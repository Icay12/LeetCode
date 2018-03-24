class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n1 = 0, n2 = 0;
        // count number of 1's in each bit
        // 00 -> 01 -> 10
        for(int i : nums) {
            int o1 = n1;
            int o2 = n2;
            n1 = (~i & o1) | (i & ~o1 & o2);
            n2 = (~i & o2) | (i & ~o1 & ~o2);
            
        }
        return n2;
    }
};