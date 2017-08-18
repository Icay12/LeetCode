class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> res;
        unordered_map<string,int> dic;
        for(string word:words) {
            ++dic[word];
        }
        if(s.length() == 0 || words.size() == 0) {
            return res;
        }
        int num = words.size();
        int length = words[0].length();
        int n = s.length();
        for(int i = 0; i <= n - num*length; ++i) {
            //string sub = s.substr(i,num*length);
            int j = 0;
            unordered_map<string,int> cnt; // appearance && times
            for(; j < num; ++j) {
                string word = s.substr(i+j*length,length);
                if(dic.find(word) != dic.end()) {
                    ++cnt[word];
                    if(cnt[word] > dic[word]) {
                        break;
                    }
                }
                else
                    break;
            }
            if(j == num) {
                res.push_back(i);
            }
        }
        return res;

    }
};