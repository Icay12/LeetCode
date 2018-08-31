class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        unordered_map<string, unordered_set<string>> hash;
        
        for(string path : paths) {
            vector<string> files;
            stringstream ss(path);
            string word;
            while(ss >> word) {
                files.push_back(word);
            }
            string pre = files[0] + "/";
            for(int i = 1; i < files.size(); ++i) {
                int a = files[i].find('(');
                int b = files[i].length()-1;
                string content = files[i].substr(a+1, b-a-1);
                string name = files[i].substr(0, a);
                hash[content].insert(pre+name);
            }
        }
        
        vector<vector<string>> res;
        for(auto p : hash) {
            if(p.second.size() == 1)
                continue;
            vector<string> v;
            
            for(string s : p.second) {
                v.push_back(s);
            }
            res.push_back(v);
        }
        return res;
    }
};