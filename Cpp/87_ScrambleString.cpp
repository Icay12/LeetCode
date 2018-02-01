class Solution {
public:
    bool isScramble(string s1, string s2) {
        if(s1 == s2)
            return true;
        if(s1.length() != s2.length())
            return false;
        vector<int> cnt(256,0);
        for(int i = 0; i < s1.size(); ++i) {
            cnt[s1[i]]++;
            cnt[s2[i]]--;
        }
        for(int i = 0; i < 256; ++i) {
            if(cnt[i] != 0)
                return false;
        }
        int len = s1.length();
        for(int i = 1; i < s1.length(); ++i) { //i cannot start from 0
            if(isScramble(s1.substr(0,i), s2.substr(0,i)) && isScramble(s1.substr(i), s2.substr(i)))
                return true;
            if(isScramble(s1.substr(0,i), s2.substr(len-i)) && isScramble(s1.substr(i), s2.substr(0,len-i)))
                return true;
        }
        return false;
    }
};