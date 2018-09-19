class Solution {
public:
    int compress(vector<char>& chars) {
        if(chars.size() == 0)
            return 0;
        int cnt = 1;
        char pre = chars[0];
        string res = "";
        
        for(int i = 1; i < chars.size(); ++i) {
            if(chars[i] == pre) {
                cnt++;
            }
            else {
                res += pre;
                if(cnt != 1) {
                    res += to_string(cnt);
                }
                pre = chars[i];
                cnt = 1;
            }
        }
        res += pre;
        if(cnt != 1) {
            res += to_string(cnt);
        }
        
        for(int i = 0 ; i < res.length(); ++i) {
            chars[i] = res[i];
        }
        
        
        return res.length();
    }
};