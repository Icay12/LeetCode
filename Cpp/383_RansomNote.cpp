class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char,int> cnt(26);
        for(int i = 0; i < magazine.length(); ++i) {
            ++cnt[magazine[i]];
        }
        for(int i = 0; i < ransomNote.length(); ++i) {
            if(--cnt[ransomNote[i]] < 0)
                return false;
        }
        return true;
    }
};