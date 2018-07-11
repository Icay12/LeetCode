class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        
        int M = matrix.size();
        if(M == 0)
            return res;
        
        int N = matrix[0].size();
        if(N == 0)
            return res;
        
        int i=0, j=0;
        bool flag = true;
        while(!(i == M-1 && j == N-1)) {
            res.push_back(matrix[i][j]);
            if(flag) {
                if(i == 0 && j != N-1) {
                    j = j + 1;
                    flag = !flag;
                }
                else if(j == N - 1) {
                    i = i + 1;
                    flag = !flag;
                }
                else {
                    i = i - 1;
                    j = j + 1;
                }
                
            }
            else {
                if(i == M-1) {
                    j = j + 1;
                    flag = !flag;
                }
                else if(j == 0) {
                    i = i + 1;
                    flag = !flag;
                }
                else {
                    i = i + 1;
                    j = j - 1;
                }
            }
        }
        res.push_back(matrix[i][j]);
        return res;

    }
};