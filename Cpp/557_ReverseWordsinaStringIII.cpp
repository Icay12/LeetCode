class Solution {
public:
    string reverseWords(string s) {
        int begin = 0;
        int indicator = 0;
        for(int i = 0; i < s.length(); ++i) {
            if(indicator == 0 && s[i] != ' ') {
                begin = i;
                indicator = 1;
            }
            if(indicator == 1 && s[i] == ' ') {
                indicator = 0;
                reverse(s.begin() + begin, s.begin() + i);
            } 
        }
        if(indicator == 1)
            reverse(s.begin() + begin, s.end());
        return s;
    }
};