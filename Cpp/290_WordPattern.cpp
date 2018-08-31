class Solution {
public:
    bool wordPattern(string pattern, string str) {
        unordered_map<char, int> hashp;
        unordered_map<string, int> hashs;
        
        int ptr = 0;
        int n = pattern.length();
        
        stringstream ss(str);
        string word;
        while(ss >> word) {
            if(ptr == n) {
                return false;
            }
            if(hashs[word] != hashp[pattern[ptr]]) {
                return false;
            }
            //last position we met the word       
            //avoid 0
            hashs[word] = ptr+1;
            hashp[pattern[ptr]] = ptr+1;
            ptr++;
        }
        
        if(ptr != n)
            return false;
        return true;
    }
};