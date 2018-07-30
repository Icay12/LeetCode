class Solution {
public:
    int numJewelsInStones(string J, string S) {
        unordered_set<char> hash;
        for(char c : J) {
            hash.insert(c);
        }
        int cnt = 0;
        for(char c : S) {
            if(hash.count(c) != 0)
                cnt++;
        }
        return cnt;
    }
};