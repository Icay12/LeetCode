class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        //character and number
        unordered_map<char,int> hash;
        int begin = 0;
        int end = 0;
        int res = 0;
        
        while(begin <= end && end < s.length()) {
            if(hash.size() < k) {
                hash[s[end++]]++;
                res = max(res, end-begin);
            }
            else{
                if(hash.count(s[end]) != 0) {
                    hash[s[end++]]++;
                    res = max(res, end-begin);
                }
                else {
                    hash[s[begin]]--;
                    if(hash[s[begin]] == 0)
                        hash.erase(s[begin]);
                    begin++;
                }
            }
            
        }
        return res;
        
    }
};