//use set
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        multiset<int> s(nums.begin(), nums.end());
        int begin = 0;
        //find begin
        for(multiset<int>::iterator it = s.begin(); it != s.end(); ++it) {
            if(*it != nums[begin])
                break;
            else
                begin++;
        }
        
        int end = (int)nums.size() - 1;
        //find end
        for(multiset<int>::reverse_iterator it = s.rbegin(); it != s.rend(); ++it) {
            if(*it != nums[end])
                break;
            else
                end--;
        }
        if(end < begin)
            return 0;
        return end - begin + 1;
        
    }
};

//find max and min
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        int begin = n-1, end = 0;
        int maxnum = nums[0], minnum = nums[n-1];
        for(int i = 0; i < n; ++i) {
            maxnum = max(maxnum, nums[i]);
            minnum = min(minnum, nums[n-1-i]);
            if(maxnum > nums[i]) {
                end = i;
            }
            if(minnum < nums[n-1-i]) {
                begin = n-1-i;
            }
        }
        if(end <= begin)
            return 0;
        else
            return end-begin+1;
    }
};