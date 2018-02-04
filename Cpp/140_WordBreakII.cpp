class Solution {
public:
    unordered_map<string, vector<string>> hash;
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        if(hash.count(s))
            return hash[s];
        int n = s.length();
        vector<string> res;
        if(find(wordDict.begin(),wordDict.end(),s) != wordDict.end()) {
            res.push_back(s);
        }
            
        for(int i = 1; i < n; ++i) {
            string word = s.substr(i);
            if(find(wordDict.begin(),wordDict.end(),word) != wordDict.end()){
                string rems = s.substr(0,i);
                vector<string> remv = combine(word,wordBreak(rems, wordDict));
                if(remv.size() != 0)
                    res.insert(res.end(),remv.begin(),remv.end());
            }
        }
        hash[s] = res;
        return res;
    }
    
    vector<string> combine(string word, vector<string> resstr) {
        int n = resstr.size();
        // if(n == 0)
        //     return resstr;
        for(int i = 0; i < n; ++i) {
            resstr[i] = resstr[i] + " " + word;
        }
        return resstr;
    }
};