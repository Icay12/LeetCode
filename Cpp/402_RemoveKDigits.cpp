class Solution {
public:
    string removeKdigits(string num, int k) {
        int n = num.length();
        int need = n - k;
        
        if(n == k)
            return "0";
        
        string res = "";
        
        for(int i = 0; i < n; ++i) {
            int flag = false;
            while(res.size() > 0 && res.back() > num[i] && k > 0) {
                res.pop_back();
                k--;
                flag = true;
            }

            if(flag || res.size() < need)
                res += num[i];
            else 
                k--;
        }
        
        while(res.size() > 0 && res[0] == '0') {
            res = res.substr(1);
        }
        
        if(res.size() == 0)
            return "0";
        return res;
        
    }
};