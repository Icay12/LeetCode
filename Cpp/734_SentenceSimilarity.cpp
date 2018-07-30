class Solution {
public:
    bool areSentencesSimilar(vector<string>& words1, vector<string>& words2, vector<pair<string, string>> pairs) {
        unordered_map<string,unordered_set<string>> hash;
        if(words1.size() != words2.size()) {
            return false;
        }
        for(auto p : pairs) {
            hash[p.second].insert(p.first);
            hash[p.first].insert(p.second);
        }
        for(int i = 0; i < words1.size(); ++i) {
            if(words1[i] != words2[i] && hash[words1[i]].find(words2[i]) == hash[words1[i]].end())
                return false;
        }
        return true;
    }
};