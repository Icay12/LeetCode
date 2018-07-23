class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        unsigned int intmin = INT_MIN;
        int n = nums.size();
        int res = 0;
        
        while(intmin != 0) {
            int cnt1 = 0;
            int cntall = INT_MIN;
            for(int i = 0; i < n; ++i) {
                if(nums[i] & 1)
                    cnt1++;
                nums[i] = nums[i] >> 1;
                cntall = cntall | nums[i];
            }
            res += cnt1 * (n - cnt1);
            if(cntall == 0)
                break;
            intmin = intmin >> 1;
            
        }
        return res;
    }
};

//TLE
class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int res = 0;
        for(int i = 0; i < nums.size(); ++i) {
            for(int j = i+1; j < nums.size(); ++j) {
                res += twoHammingDistance(nums[i],nums[j]);
            }
        }
        return res;
    }
    
    int twoHammingDistance(int a, int b) {
        int cnt = 0, m = a^b;
        while(m>0) {
            cnt++;
            m = m & (m-1);
        }
        return cnt;
    }
};