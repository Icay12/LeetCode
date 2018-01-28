class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.size() == 0 || matrix[0].size() == 0)
            return 0;
        vector<int> row(matrix[0].size(),0);
        int maxArea = 0;
        for(int i = 0; i < matrix.size(); ++i) { //number of rows
            for(int j = 0; j < matrix[0].size(); ++j) {
                if(matrix[i][j] == '0')
                    row[j] = 0;
                else
                    ++row[j];
            }
            int area = maxRectangleRow(row);
            maxArea = max(area, maxArea);
        }
        return maxArea;
    }
    
    int maxRectangleRow(vector<int>& row) {
        row.push_back(0);
        vector<int> smallest;
        int maxArea = 0;
        for(int i = 0; i < row.size(); ++i) {
            while(smallest.size() != 0 && row[i] < row[smallest.back()]) {
                int h = row[smallest.back()];
                smallest.pop_back();
                int area;
                if(smallest.size() == 0)
                    area = h * i;
                else
                    area = h * (i - 1 - smallest.back());
                maxArea = max(area, maxArea);
            }
            smallest.push_back(i);
        }
        return maxArea;
    }
};