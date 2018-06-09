class Solution {
public:
    vector<string> removeComments(vector<string> &source) {
        bool cm = false; // if is in /*

        vector<string> res;
        string tmp = "";
        for (int i = 0; i < source.size(); ++i) {
            removeLine(source[i], cm, res, tmp);
        }
        return res;
    }
    
    void removeLine(string s, bool &cm, vector<string> &res, string &tmp) {
        if(!cm) {
            int a = s.find("//");
            int b = s.find("/*");
            
            if(a >= 0 && (a < b || b < 0)) {  //consider // case
                if(tmp + s.substr(0, a) != ""){
                    res.push_back(tmp + s.substr(0, a));
                    tmp = "";
                }
                return;
            }
            else if(b >= 0 && (b < a || a < 0)) {  //consider /* case
                int c = s.substr(b+2).find("*/");
                tmp += s.substr(0,b);
                //if we can find */ in the same line
                if(c >= 0) {
                    removeLine(s.substr(b+2+c+2), cm, res, tmp);
                }
                else {  //if */ is in a different line
                    cm = true;
                    return;
                }
            }
            else {
                if(tmp + s != "") {
                    res.push_back(tmp + s);
                    tmp = "";
                }
                return;
            }
        }
        else {
            int c = s.find("*/");
            if(c < 0) {
                return;
            }
            else {
                cm = false;
                removeLine(s.substr(c+2), cm, res, tmp);
            }
        }
        
    }
};