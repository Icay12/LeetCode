class Solution {
public:
    bool isMatch(string s, string p) {
        int lenp = p.length();
        int lens = s.length();
        int stars = -1;
        int starp = -1;
        int i,j;
        for(i=0, j=0; i < lens; ++i, ++j) {
            if(j >= lenp) {
                if(starp >= 0) {
                    i = stars;
                    j = starp;
                    stars = stars + 1;
                    continue;
                }
                else {
                    return false;
                }

            }
            if(s[i] == p[j] || p[j] == '?') {
                continue;
            }
            else if(p[j] == '*') {
                stars = i;
                starp = j;
                i = i - 1;
            }
            else {
                if(starp >= 0) {
                    i = stars;
                    j = starp;
                    stars = stars + 1;
                }
                else {
                    return false;
                }
            }
        }
        while(p[j] == '*')
            ++j;
        if(j == lenp)
            return true;
        else
            return false;
    }
};