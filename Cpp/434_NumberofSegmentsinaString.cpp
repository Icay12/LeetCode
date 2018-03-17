class Solution {
public:
    int countSegments(string s) {

        int res = 0;
        int begin = 1;
        for(char c : s) {
            if(begin && c != ' ') {
                ++res;
                begin = 0;
            }
            else if(!begin && c == ' ') {
                begin = 1;
            }
        }
        return res;
    }
};