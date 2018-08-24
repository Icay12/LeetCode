class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        unordered_set<string> ban(banned.begin(), banned.end());
        unordered_map<string, int> hash;
        for(auto &c : paragraph) {
            c = isalpha(c) ? tolower(c) : ' ';
        }
        
        stringstream ss(paragraph);
        string s;
        while(ss >> s) {
            if(ban.count(s) != 0)
                continue;
            hash[s]++;
        }
        
        int maxNum = INT_MIN;
        string res = "";
        for(auto p : hash) {
            if(p.second > maxNum) {
                res = p.first;
                maxNum = p.second;
            }
        }
        return res;
    }
};