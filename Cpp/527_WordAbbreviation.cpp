class Solution {
public:
    vector<string> wordsAbbreviation(vector<string>& dict) {
        unordered_map<string, unordered_set<int>> abbr;
        vector<string> res(dict.size());
        for(int i = 0; i < dict.size(); ++i) {
            if(dict[i].length() <= 3) {
                res[i] = dict[i];
            }
            else {
                string initial = "";
                initial += dict[i][0];
                initial += to_string(dict[i].length()-2);
                initial += dict[i][dict[i].length()-1];
                
                abbr[initial].insert(i);
                res[i] = initial;
                // cout << initial << endl;

            }
        }
        
        for(auto p : abbr) {
            if(p.second.size() > 1) {
                // cout << p.second.size() << endl;
                resolve(p.second, dict, res);
            }
        }
        
        return res;
    }
    
    void resolve(unordered_set<int>& words, vector<string>& dict, vector<string>& res) {
        int len = dict[*words.begin()].length();
        string prefix = "";
        for(int a : words) {
            string word = dict[a];
            for(int i = 2; i <= len-2; ++i) {
                if( i == len - 2) {
                    res[a] = word;
                    break;
                }
                    
                string prefix = word.substr(0, i);
                cout << prefix << endl;
                bool find = false;
                for(int b : words) {
                    if(b == a)
                        continue;
                    string wordB = dict[b];
                    if(wordB.find(prefix) == 0) {
                        // cout << wordB.find("tru") << endl;
                        find = true;
                        break;
                    }
                }
                if(!find) {
                    // cout << "!find" << endl;
                    res[a] = prefix + to_string(len-i-1) + word[len-1];
                    break;
                }
            }
        }
    }
};