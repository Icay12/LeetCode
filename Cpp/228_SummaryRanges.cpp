class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> res;
        if(nums.size() == 0)
            return res;
        string range = to_string(nums[0]);
        int begin = nums[0];
        int last = nums[0];
        for(int i = 1; i < nums.size(); ++i) {
            if(nums[i] == nums[i-1]+1) {
                last = nums[i];
            }
            else if(last != begin){
                range += "->";
                range += to_string(last);
                res.push_back(range);
                last = nums[i];
                begin = nums[i];
                range = to_string(nums[i]);
            }
            else {
                res.push_back(range);
                range = to_string(nums[i]);
                last = nums[i];
                begin = nums[i];
            }
        }
        if(last == begin) {
            res.push_back(range);
        }
        else {
            range += "->";
            range += to_string(last);
            res.push_back(range);
        }
        return res;
    }
};