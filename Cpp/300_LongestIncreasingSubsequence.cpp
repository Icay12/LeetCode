//DP Solution

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int maxlen = 0;
        vector<int> dp(nums.size(),1);
        for(int i = 0; i < nums.size(); ++i) {
            for(int j = i-1; j >= 0; --j) {
                if(nums[i] > nums[j]) {
                    dp[i] = max(dp[j]+1, dp[i]);
                }
            }
            maxlen = max(maxlen, dp[i]);
        }
        return maxlen;
    }
};



// O(nlogn) Solution

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if(nums.size() == 0)
            return 0;
        int maxlen = 1;
        vector<int> tail((int)nums.size(),0);
        tail[0] = nums[0];
        for(int i = 1; i < nums.size(); ++i) {
            if(nums[i] < tail[0])
                tail[0] = nums[i];
            else if(nums[i] > tail[maxlen-1]) {
                tail[maxlen] = nums[i];
                maxlen += 1;
            }     
            else {
                int index = binarySearch(tail,0,maxlen-1, nums[i]);
                tail[index] = nums[i];
            }
        }
        return maxlen;
    }
    
    int binarySearch(vector<int>& nums, int begin, int end, int k) {
        while(begin <= end) {
            int mid = (begin + end) / 2;
            if(nums[mid] == k)
                return mid;
            else if(nums[mid] > k)
                end = mid - 1;
            else
                begin = mid + 1;
        }
        return begin;
    }
};