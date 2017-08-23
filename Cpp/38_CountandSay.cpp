class Solution {
public:
    string countAndSay(int n) {
        if(n == 1) {
            return "1";
        }
        string preStr = countAndSay(n-1);
        int i = 0;
        string res = "";
        while(i < preStr.length()) {
            int pt = i + 1;
            while(pt < preStr.length() && preStr[i] == preStr[pt])
                ++pt;
            res += (pt - i + '0');
            res += preStr[i];
            i = pt;
        }
        return res;
    }
};