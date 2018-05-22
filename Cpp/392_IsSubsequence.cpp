class Solution {
public:
    bool isSubsequence(string s, string t) {
        int slen = s.length();
        int tlen = t.length();
        int i, j;
        for(i = 0, j = 0; i < slen, j < tlen; ++j) {
            if(s[i] == t[j]) 
                i++;
        }
        return i == slen;
    }
};