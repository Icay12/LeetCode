class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> Roman = { {'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000}}; //good data structure
        int sum = Roman[s.back()]; //clever
        for(int i = 0; i < s.length() - 1; ++i) {
            if(Roman[s[i]] < Roman[s[i+1]]) {
                sum -= Roman[s[i]];
            }
            else {
                sum += Roman[s[i]];
            }
        }
        return sum;
    }
};