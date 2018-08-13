class Solution {
public:
    bool checkRecord(string s) {
        int A = 0; //number of 'A'
        int L = 0; //status of 'L'
        
        for(char c : s) {
            if(c == 'A') {
                A++;
            }
            if(c == 'L') {
                L++;
            }
            else {
                L = 0;
            }
            
            if(A >= 2 || L >= 3)
                return false;
        }
        return true;
    }
};