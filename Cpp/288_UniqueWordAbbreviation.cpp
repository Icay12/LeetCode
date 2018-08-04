class ValidWordAbbr {
    unordered_map<string, unordered_set<string>> hash;
public:
    ValidWordAbbr(vector<string> dictionary) {
        for(string s : dictionary) {
            if(s.length() <= 2) {
                continue;
            }
                
            string abbr = "";
            abbr += s[0];
            abbr += to_string((int)s.length()-2);
            abbr += s[(int)s.length()-1];
            hash[abbr].insert(s);
        }
    }
    
    bool isUnique(string word) {
        if(word.length() <= 2)
            return true;
        string abbr = "";
        abbr += word[0];
        abbr += to_string((int)word.length()-2);
        abbr += word[(int)word.length()-1];
        // cout << abbr << endl;
        if(hash[abbr].size() >= 2)
            return false;
        if(hash[abbr].count(word) == 1 || hash[abbr].size() == 0)
            return true;
        else
            return false;
    }
};

/**
 * Your ValidWordAbbr object will be instantiated and called as such:
 * ValidWordAbbr obj = new ValidWordAbbr(dictionary);
 * bool param_1 = obj.isUnique(word);
 */