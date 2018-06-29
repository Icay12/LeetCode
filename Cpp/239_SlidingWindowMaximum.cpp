class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        vector<int> res;

        for(int i = 0; i < nums.size(); ++i) {
            while(!dq.empty() && nums[i] >= nums[dq.back()])
                dq.pop_back();
            while(!dq.empty() && (i - dq.front()) > k-1)
                dq.pop_front();
            dq.push_back(i);
            if(i+1 >= k) {
                res.push_back(nums[dq.front()]);
            }
        }

        return res;
        
    }
};