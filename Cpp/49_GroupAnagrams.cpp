class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<int> primes = {2, 3, 5, 7, 11 ,13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 107};
        unordered_map<long long,vector<string>> dic;
        int size = strs.size();
        for(string s: strs) {
            long long key = 1;
            for(char c: s) {
                key *= primes[c-'a'];
            }
            dic[key].push_back(s);
        }
        vector<vector<string>> result;

        for(unordered_map<long long,vector<string>>::iterator i = dic.begin(); i != dic.end(); ++i) {
            vector<string> member = i->second;
            vector<string> ikind;
            for(string s: member) {
                ikind.push_back(s);
            }
            result.push_back(ikind);
        }
        return result;
    }
};