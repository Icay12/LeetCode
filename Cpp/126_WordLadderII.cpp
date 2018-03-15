class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        vector<vector<string>> res;
        unordered_set<string> wordDict(wordList.begin(), wordList.end());
        queue<vector<string>> paths;
        unordered_set<string> toDelete;
        // int level = 1;
        int minLevel = INT_MAX;
        paths.push({beginWord});
        while(!paths.empty()) {
            int n = paths.size();
            for(auto it : toDelete) {
                wordDict.erase(it);
            }
            toDelete.clear();
            for(int i = 0; i < n; ++i) {
                vector<string> path = paths.front();
                paths.pop();
                string word = path.back();
                if(path.size() <= minLevel) {

                    for(int j = 0; j < word.length(); ++j) {
                        for(char a = 'a'; a < 'z'; ++a) {                           
                            string tmpword = word;
                            tmpword[j] = a;
                            //move to the line to the back, and pass TLE
                            // vector<string> newpath = path;  
                            if(wordDict.find(tmpword) != wordDict.end()) {
                                vector<string> newpath = path;
                                newpath.push_back(tmpword);
                                toDelete.insert(tmpword);
                                //cannot delete here, beause other paths at the same level may need to use the same word.
                                // wordDict.erase(tmpword);
                                if(tmpword == endWord) {
                                    res.push_back(newpath);
                                    minLevel = newpath.size();
                                }
                                else
                                    paths.push(newpath);
                            }
                        }
                    }
                }
                else
                    break;
                   
            }
        }
        return res;
        
    }
};
