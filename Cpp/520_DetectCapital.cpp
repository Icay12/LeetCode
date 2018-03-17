class Solution {
public:
    bool detectCapitalUse(string word) {
        if(word.length() == 0 || word.length() == 1)
            return true;
        bool cap;
        int begin = 2;
        if(!isCapital(word[0])) {
            cap = false;
            begin = 1;
        }
        else if(isCapital(word[1])) {
            cap = true;
        }
        else {
            cap = false;
        }

        for(int i = begin; i < word.length(); ++i) {
            if(isCapital(word[i])  != cap)
                return false;
        }
        return true;
        
    }
    bool isCapital(char c) {
        if(c >= 'A' && c <= 'Z')
            return true;
        else
            return false;
    }
};