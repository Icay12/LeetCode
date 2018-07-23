class Solution {
public:
    string licenseKeyFormatting(string S, int K) {
        string res;
        //iterate S reversely
        int count = 0;
        for(auto i = S.rbegin(); i != S.rend(); ++i) {
            if(*i == '-')
                continue;
            res+=toupper(*i);
            count++;
            if(count == K) {
                res+='-';
                count = 0;
            }
            
        }
        reverse(res.begin(), res.end());
        if(*res.begin() == '-')
            res = res.substr(1);
        return res;
    }
};