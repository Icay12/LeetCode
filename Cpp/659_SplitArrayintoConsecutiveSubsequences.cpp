class Solution {
public:
    bool isPossible(vector<int>& nums) {
        if(nums.size() < 3)
            return false;
        unordered_map<int, int> cnt, tail;
        for(auto a : nums) {
            cnt[a]++;
        }
        
        for(auto a : nums) {
            if(cnt[a] == 0)
                continue;
            if(tail[a-1] == 0) {
                if(cnt[a+1] && cnt[a+2]) {
                    cnt[a]--;
                    cnt[a+1]--;
                    cnt[a+2]--;
                    tail[a+2]++;
                }
                else {
                    return false;
                }
            }
            else {
                tail[a-1]--;
                tail[a]++;
                cnt[a]--;
            }
        }
        return true;
    }
};