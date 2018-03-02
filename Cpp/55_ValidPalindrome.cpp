class Solution {
public:
    bool isPalindrome(string s) {
        if(s.length() == 0)
            return true;
        int begin = 0;
        int end = (int)s.length()-1;
        while(begin < end) {
            while(isalnum(s[begin]) == false && begin < end) begin++;
            while(isalnum(s[end]) == false && begin < end) end--;
            if(begin < end && toupper(s[begin]) != toupper(s[end])) {
                
                return false;
            }
            begin++, end--;
                
        }
        return true;
    }
};