class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int cnt = 0;
        int sum = 0;
        unordered_map<int, int> hash;
        hash[0] = 1;
         
        for(int a : nums) {
            sum += a;
            cnt += hash[sum - k];
            hash[sum]++;
        }
        
        return cnt;
 
        
    }
};


// we cannot use sliding window because num can be negative