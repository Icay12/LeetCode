class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> str;
        for(int i : nums) {
            str.push_back(to_string(i));
        }
        sort(str.begin(), str.end(), [](const string &a, const string &b) {
            return (a+b)>(b+a);
        });
        string res = "";
        for(string s : str) {
            res += s;
        }
        if(str.size() != 0 && res[0] == '0') {
            return "0";
        }
        return res;
    }
};