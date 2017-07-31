class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        addParenthesis(result,"",0,0,n);
        return result;
        
    }
    //the parameter must be: vector<string> &list
    void addParenthesis(vector<string> &list, string str, int open, int close, int n) {
        if(str.length() == 2*n) {
            list.push_back(str);
            return;
        }
        if(open < n) {
            addParenthesis(list,str+"(",open+1,close,n);
        }
        if(close < open) {
            addParenthesis(list,str+")",open,close+1,n);
        }
    }
};