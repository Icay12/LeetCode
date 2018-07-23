class Solution {
public:
    int wordsTyping(vector<string>& sentence, int rows, int cols) {
        // int cnt = 0;
        int n = sentence.size();
        int ptr = 0;
        int irow = 0;
        while(irow < rows) {
            int icol = cols;
            //fill one row
            while(icol > 0) {
                if(icol >= sentence[ptr%n].length()) {
                    
                    icol-=sentence[ptr%n].length();
                    icol-=1;
                    ptr++;
                }
                else {
                    break;
                }
            }
                
            irow++;
            if(ptr%n == 0 && rows/2 >= irow) {
                ptr = rows/irow*(ptr);
                irow = rows - rows % irow;
            }
        }
        return ptr/n;
    }
};