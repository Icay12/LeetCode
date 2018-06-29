class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length())
            return false;
        vector<int> hash(26, 0);
        for(char c : s) {
            int i = c - 'a';
            hash[i]++;
        }
        for(char c : t) {
            int i = c - 'a';
            hash[i]--;
            if(hash[i] < 0)
                return false;
        }
        return true;
    }
};