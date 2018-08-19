class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        unordered_map<char, int> hash;
        for(char c : p) {
            hash[c]++;
        }
        int n = p.length();
        vector<int> res;
        int begin = 0,end = 0;
        while(begin <= end && end < s.length()) {

            if(hash[s[end]] == 0) {
                while(begin < end) {
                    if(s[begin] == s[end]) {
                        begin++;
                        end++;
                        break;
                    }
                    hash[s[begin]]++;
                    begin++;
                }
                if(begin == end) {
                    begin++,end++;
                }     
                // cout << hash[begin] << " " << s[be;
                // cout << begin<< " " << end << endl;
            }
            else {
                // cout << begin<< " " << end << endl;
                hash[s[end]]--;
                // cout << "else" << endl;
                if(end - begin + 1 == n) {
                    // cout << "n" << endl;
                    res.push_back(begin);
                    hash[s[begin]]++;
                    begin++;
                    
                        
                }
                
                end++;
            }
            
        }
        return res;
    }
};