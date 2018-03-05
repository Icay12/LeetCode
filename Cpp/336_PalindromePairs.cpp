class Solution {
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        vector<vector<int>> res;
        unordered_map<string, int> dict;
        for(int i = 0; i < words.size(); ++i) {
            string key = words[i];
            reverse(key.begin(), key.end());
            dict[key] = i;
        }
        // if "" is contained, find all palindrome words
        if(dict.find("") != dict.end()) {
            for(int i = 0; i < words.size(); ++i) {
                if(isPalindrome(words[i]) && words[i] != "") {
                    res.push_back({dict[""],i});
                }
            }
        }
        for(int i=0; i < words.size(); ++i) {
            for(int j=0; j < words[i].length(); ++j) {
                string left = words[i].substr(0,j);
                string right = words[i].substr(j, (int)words[i].length()-j);
                if(isPalindrome(right) && dict.find(left) != dict.end() && dict[left] != i) {
                    res.push_back({i,dict[left]});
                }
                if(isPalindrome(left) && dict.find(right) != dict.end() && dict[right] != i) {
                    res.push_back({dict[right],i});
                }
            }
        }
        return res;
    }
    
    bool isPalindrome(string word) {
        if(word.length() == 0)
            return true;
        int i = 0;
        int j = word.length() - 1;
        while(i < j) {
            if(word[i] != word[j])
                return false;
            ++i, --j;
        }
        return true;
    }
};