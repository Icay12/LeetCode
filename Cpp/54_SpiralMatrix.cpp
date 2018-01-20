class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        int m = matrix.size();
        if(m == 0) {
            return res;
        }
        int n = matrix[0].size();
        if(n == 0) {
            return res;
        }        
        int loop = 0;
        int k = m*n;
        int i = 0, j = 0;
        while( (k--)>0 ) {
            res.push_back(matrix[i][j]);

            if(i == loop && j < n-loop-1) {
                ++j;
            }
            else if(i < m-loop-1 && j == n-loop-1) {
                ++i;
            }
            else if(i == m-loop-1 && j > loop) {
                --j;
            }
            else if(i > loop && j == loop) {
                if(i == loop + 1) {
                    ++loop;
                    ++j;
                }  
                else
                    --i;
            }
        }

        return res;
    }
};