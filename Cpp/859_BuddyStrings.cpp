class Solution {
public:
    bool buddyStrings(string A, string B) {
        if(A.length() != B.length())
            return false;
        
        //sp case
        if(A == B) {
            set<char> c(A.begin(), A.end());
            if(c.size() == A.size())
                return false;
            else
                return true;
        }
        
        int pos1 = -1, pos2 = -1;
        for(int i = 0; i < A.length(); ++i) {
            if(A[i] != B[i]) {
                if(pos1 < 0) {
                    pos1 = i;
                }
                else if(pos2 < 0) {
                    pos2 = i;
                }
                else {
                    return false;
                }
            }
        }
        
        if(pos1 < 0 || pos2 < 0) {
            return false;
        }
        if(A[pos1] == B[pos2] && A[pos2] == B[pos1]) {
            return true;
        }
        return false;
        
    }
};