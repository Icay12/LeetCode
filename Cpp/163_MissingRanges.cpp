class Solution {
public:
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        vector<string> res;
        long long begin = lower;
        for(int i = 0; i < nums.size(); ++i) {
            if(nums[i] > begin) {
                int end = nums[i] - 1;
                if(begin == end) {
                    res.push_back(to_string(begin));
                }
                else {
                    string s = to_string(begin);
                    s+= "->";
                    s+= to_string(end);
                    res.push_back(s);
                }
            }
            begin = (long long)nums[i]+1; //be care of the range of int
        }
        if(begin == upper) {
            res.push_back(to_string(begin));
        }
        else if(begin < upper) {
            string s = to_string(begin);
            s+= "->";
            s+= to_string(upper);
            res.push_back(s);
        }
        
        return res;
    }
};