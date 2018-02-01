class Solution {
public:
    int numDecodings(string s) {
        int len = s.length();
        if(len == 0 || s.front() == '0')
            return 0;
        int s1 = 1, s2 = 1;
        int snow = 1;
        for(int i = 1; i < len; ++i) {
            if(s[i] == '0')
                s1 = 0;
            snow = s1;
            if(s[i-1] == '1' || s[i-1] == '2' && s[i] <= '6' ) {
                snow += s2;
            }
            s2 = s1;
            s1 = snow;
        }
        return snow;
    }
};