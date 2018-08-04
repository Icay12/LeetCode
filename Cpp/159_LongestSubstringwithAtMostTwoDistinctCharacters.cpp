class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        int begin = 0, end = 0;
        unordered_map<char, int> hash;
        int maxlen = 0;
        while(begin <= end && end < s.length()) {
            if(hash.size() < 2 || hash.count(s[end])!=0) {
                hash[s[end]]++;
                end++;
                continue;
            }
            maxlen = max(maxlen, end - begin);
            //hash size == 2 && s[i] not in hash
            while(hash.size() == 2) {
                hash[s[begin]]--;
                if(hash[s[begin]] == 0)
                     hash.erase(s[begin]);
                begin++;
            }
            hash[s[end]]++;
            end++;
        }
                     
        maxlen = max(maxlen, end - begin);
        return maxlen;
    }
};