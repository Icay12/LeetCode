class Solution {
public:
    bool isNumber(string s) {
        int i = 0;
        int len = s.length();
        while(i < len && s[i] == ' ') {
            i++;
        }
        if(i == len)
            return false;
        if(s[i] == '+' || s[i] == '-')
            ++i;
        int sign = 0, num = 0;
        for(; i < len && (s[i] >= '0' && s[i] <= '9' || s[i] == '.'); ++i) {
            if(s[i] == '.')
                sign++;
            else
                num++;
        }
        if(sign > 1 || num < 1)
            return false;
        if(i == len)
            return true;
        num = 0;
        if(s[i] == 'e') {
            i++;
            if(s[i] == '+' || s[i] =='-')
                ++i;
            for(;i<len && (s[i] >='0' && s[i] <='9');++i) {
                num++;
            }
            if(num < 1)
                return false;
        }
        while(i < len && s[i] == ' ')
            i++;
        if(i == len)
            return true;
        return false;
    }
};