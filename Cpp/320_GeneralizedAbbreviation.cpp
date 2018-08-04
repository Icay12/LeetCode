class Solution {
public:
    vector<string> generateAbbreviations(string word) {
        vector<string> res;
        generateAbbr(word, "", 0, 0, res);
        return res;
    }
    
    void generateAbbr(string &word, string abbr, int pos, int cnt, vector<string> &res) {
        if(pos == word.length()) {
            res.push_back( abbr + (cnt == 0? "" : to_string(cnt) ) );
            return;
        }
        generateAbbr(word, abbr, pos+1, cnt+1, res);
        generateAbbr(word, abbr + (cnt == 0? "" : to_string(cnt)) + word[pos], pos+1, 0, res);
    }
};