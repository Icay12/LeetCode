class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        vector<char> sequence = {'(',')'};
        vector<string> res;
        remove(s, 0, 0, sequence, res);
        return res;
    }
    void remove(string s, int last_i, int last_j, vector<char> seq, vector<string>& res) { // cannot be vector<char>& seq
        int stack = 0;
        for(int i = last_i; i < s.length(); ++i) {
            if(s[i] == seq[0]) stack++;
            if(s[i] == seq[1]) stack--;
            if(stack >= 0)
                continue;
            //stack < 0
            for(int j = last_j; j <= i; ++j) {
                if(s[j] == seq[1] && (j == last_j || s[j-1] != seq[1])) {
                    remove(s.substr(0,j)+s.substr(j+1) , i, j, seq, res);
                }
            }
            return;        
        }
        string rs = s;
        reverse(rs.begin(), rs.end());
        if(seq[0] == '(') {
            seq[0] = ')';
            seq[1] = '(';
            remove(rs,0,0,seq, res);
        }
        else {
            res.push_back(rs);
        }
        
    }
};