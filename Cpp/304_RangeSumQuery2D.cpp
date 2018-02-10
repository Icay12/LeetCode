class NumMatrix {
public:
    NumMatrix(vector<vector<int>> matrix) {
        if(matrix.size() == 0 || matrix[0].size() == 0) 
            accu.push_back(vector<int>());
        else {
            accu.push_back(vector<int>(matrix[0].size()+1, 0));
            for(int i = 0; i < matrix.size(); ++i) {
                vector<int> accuRow = accu.back();

                for(int j = 0; j < matrix[0].size(); ++j) {
                    accuRow[j+1] = accuRow[j] + accuRow[j+1] + matrix[i][j] - accu[i][j];
                
                }
            
                accu.push_back(accuRow);
            }
        }
        
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int rowmin = min(row1,row2);
        int rowmax = max(row1,row2);
        int colmin = min(col1,col2);
        int colmax = max(col1,col2);
        return accu[rowmax+1][colmax+1] - accu[rowmin][colmax+1] - accu[rowmax+1][colmin] +  accu[rowmin][colmin];
    }
    
private:
    vector<vector<int>> accu;
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix obj = new NumMatrix(matrix);
 * int param_1 = obj.sumRegion(row1,col1,row2,col2);
 */


