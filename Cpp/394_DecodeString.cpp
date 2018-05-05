class Solution {
public:
    string decodeString(string s) {
        int i = 0;
        return decode(s, i);
        
    }
    string decode(string s, int& i) {
        string res = "";
        while(i < s.length() && s[i] != ']') {
            //deal with letters outside square brackets
            if(!isdigit(s[i])) {
                res += s[i++];
                continue;
            }
            
            int num = 0;
            while(isdigit(s[i])) {
                num = num*10 + (s[i++]-'0');
            }
            // cout << num << endl;
            i++; // [
            string inside = decode(s, i);
            i++; // ]
            while(num > 0) {
                res += inside;
                num--;
            }
                
        }
        return res;
    }
};