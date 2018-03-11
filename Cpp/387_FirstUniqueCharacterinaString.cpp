class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> dic(26);
        for(auto c : s) {
            ++dic[c];
        }
        for(int i = 0; i < s.length(); ++i) {
            if(dic[s[i]] == 1)
                return i;
        }
        return -1;
        
    }
};