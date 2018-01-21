class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        
        vector<vector<int>> res(n, vector<int>(n));
        if(n <= 0)
            return res;
        
        int loop = 0;
        int k = 0;
        int i = 0, j = 0;
        while((k++) < n*n) {
            res[i][j] = k;
            if(i == loop && j < n - 1 - loop) {
                ++j;
            }
            else if(i < n - 1 - loop && j == n - 1- loop) {
                ++i;
            }
            else if(i == n - 1 - loop && j > loop) {
                --j;
            }
            else if(i > loop && j == loop) {
                if(i == loop + 1) {
                    ++j;
                    ++loop;
                } 
                else
                    --i;
            }
        }
        return res;
    }
};