class Solution {
public:
    int repeatedStringMatch(string A, string B) {
        for(int i = 0; i < A.length(); ++i) {
            for(int j = 0; j <= B.length(); ++j) {
                if(j == B.length())
                    return (i + j) / A.length() + ((i+j)%A.length()==0?0:1);
                if(A[(i+j)%A.length()] != B[j])
                    break;
            }
        }
        return -1;
    }
};