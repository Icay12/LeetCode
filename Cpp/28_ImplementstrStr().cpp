class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.length() == 0) {
            return 0;
        }
        if(haystack.length() < needle.length()) {
            return -1;
        }
        for(int i = 0; i <= haystack.length()-needle.length(); ++i) {
            int phay = i;
            int pneed;
            for(pneed = 0; pneed < needle.length(); ++pneed) {
                if(haystack[phay++] != needle[pneed]) {
                    break;
                }
            }
            if(pneed == needle.length()) {
                return i;
            }
        }
        return -1;
    }
};