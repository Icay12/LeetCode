class Solution {
public:
    bool checkValidString(string s) {
        //max ( that could be matched
        //min ( that must be matched
        int maxleft = 0;
        int minleft = 0;
        for(auto c: s) {
            if(c == '(') {
                ++maxleft;
                ++minleft;
            }
            else if(c == ')') {
                --maxleft;
                --minleft;
                if(minleft < 0)
                    minleft = 0;
            }
            else { //c == '*'
                ++maxleft;
                --minleft;
                if(minleft < 0)
                    minleft = 0;
            }
            if(maxleft < 0)
                return false;
        }
        return minleft == 0;
    }
};

class Solution {
public:
    bool checkValidString(string s) {
        //max ) that could be matched
        //min ) that must be matched
        int maxright = 0;
        int minright = 0;
        for(auto c: s) {
            if(c == '(') {
                --maxright;
                --minright;
            }
            else if(c == ')') {
                ++maxright;
                ++minright;
                if(minright > 0)
                    minright = 0;
            }
            else { //c == '*'
                --maxright;
                ++minright;
                if(minright > 0)
                    minright = 0;
            }
            if(maxright > 0)
                return false;
        }
        return minright == 0;
    }
};