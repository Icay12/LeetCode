class Solution {
public:
    int countSubstrings(string s) {
        int count = 0; 
        int len = s.length();
        for(int i = 0; i < len; ++i) {
            
            for(int begin = i, end = i; begin >= 0, end < len; --begin, ++end) {
                if(s[begin] == s[end])
                    count++;
                else
                    break;
            }
            for(int begin = i, end = i+1; begin >= 0, end < len; --begin, ++end) {
                if(s[begin] == s[end])
                    count++;
                else
                    break;
            }
        }
        return count;
    }
};