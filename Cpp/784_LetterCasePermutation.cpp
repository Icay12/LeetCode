class Solution {
public:
    vector<string> letterCasePermutation(string S) {
        
        vector<string> res;
        res.push_back("");
        for(char c : S) {
            int n = res.size();
            for(int i = 0; i < n; ++i) {
                // res[i] += c; // should not be here
                if(isalpha(c) && islower(c)) {
                    res.push_back(res[i]+(char)toupper(c));
                }
                else if(isalpha(c) && isupper(c)) {
                    res.push_back(res[i]+(char)tolower(c));
                }
                res[i] += c;
            }
        }
        return res;
    }
};