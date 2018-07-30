class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = m == 0? 0 : matrix[0].size();
        if(m == 0 || n == 0)
            return true;
        //iterate the first row
        for(int i = 0; i < n; ++i) {
            int a = 1, b = i+1;
            while(a < m && b < n) {
                if(matrix[a][b] != matrix[0][i])
                    return false;
                a++, b++;
            }
        }
        
        //iterate the first column
        for(int j = 0; j < m; ++j) {
            int a = j+1, b = 1;
            while(a < m && b < n) {
                if(matrix[a][b] != matrix[j][0])
                    return false;
                a++, b++;
            }
        }
        return true;
    }
};