class NumMatrix {
    vector<vector<int>> bit;
    int row_num = 0;
    int col_num = 0;
    
    void update_by_diff(int row, int col, int diff) {
        while(col < col_num) {
            bit[row][col] += diff;
            col += (col & -col);
        }
    }
    
    int rowSum(int row, int col) {
        int res = 0;
        while(col > 0) {
            res += bit[row][col];
            col -= (col & -col);
        }
        return res;
    }
    
    int rowSumRegion(int row, int col1, int col2) {
        // cout << "rowSumRegion " << rowSum(row,col2) - rowSum(row,col1-1);
        return rowSum(row,col2) - rowSum(row,col1-1);
    }
    
public:
    NumMatrix(vector<vector<int>> matrix) {
        row_num = matrix.size();
        if(row_num == 0)
            return;
        col_num = matrix[0].size()+1;
        if(col_num == 1)
            return;
        bit = vector<vector<int>>(row_num, vector<int>(col_num,0));
        
        for(int i = 0; i < row_num; ++i) {
            for(int j = 0; j < col_num; ++j) {
                update(i,j,matrix[i][j]);
            }
        }
    }
    
    void update(int row, int col, int val) {
        int pre_val = rowSumRegion(row,col+1,col+1);
        update_by_diff(row, col+1, val - pre_val);
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int res = 0;
        for(int r = row1; r <= row2; ++r) {
            res += rowSumRegion(r, col1+1, col2+1);
        }
        return res;
    }
    
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix obj = new NumMatrix(matrix);
 * obj.update(row,col,val);
 * int param_2 = obj.sumRegion(row1,col1,row2,col2);
 */