class Solution {
    
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<string, int> visited;
        int n = s.length();
        vector<string> res;
        if(n < 10)
            return res;
        string test = "";
        for(int i = 9; i < s.length(); ++i) {
            if(test == "") {
                test = s.substr(0,10);
                visited[test]++;
            }
            else {
                test = test.substr(1) + s[i];
                visited[test]++;
            }
        }
        
        for(auto p : visited) {
            if(p.second > 1) {
                res.push_back(p.first);
            }
        }
        return res;
    }
};