

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        vector<int> res(2,0);
        int diff = 0;
        for(int a : nums) {
            diff ^= a;
        }
        diff = diff & (-diff);
        
        for(int a : nums) {
            if(a & diff) {
                res[0] ^= a;
            }
            else {
                res[1] ^= a;
            }
        }
        return res;
    }
};