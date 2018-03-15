//left shifted
class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int len = s.length();
        if(len == 0)
            return false;
        for(int i = 1; i <= len/2; ++i) {
            if(len % i == 0) {
                string leftshifted = s.substr(i);
                leftshifted += s.substr(0,i);
                if(leftshifted == s)
                    return true;
            }
        }
        return false;
    }
};


//new combination
class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int len = s.length();
        if(len == 0)
            return false;
        for(int i = 1; i <= len/2; ++i) {
            if(len % i == 0) {
                string news;
                string element = s.substr(0,i);
                for(int j = 0; j < len / i; ++j) {
                    news+=element;
                }
                if(news == s)
                    return true;
            }
        }
        return false;
    }
};