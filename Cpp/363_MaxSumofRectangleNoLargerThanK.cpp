class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        if(matrix.size() == 0 || matrix[0].size() ==0)
            return 0;
        int m = matrix.size();
        int n = matrix[0].size();
        int maxSum = INT_MIN;
        
        for(int i = 0; i < n; ++i) {
            vector<int> sum(m, 0);
            for(int j = i; j < n; ++j) {
                for(int p = 0; p < m; ++p) {
                    sum[p] += matrix[p][j];
                }
                             
                int tmpSum = 0;
                int tmpMax = INT_MIN;
                
                set<int> accu;
                accu.insert(0); // make sure the first element can be added
                for(int p = 0; p < m; ++p) {
                    tmpSum += sum[p];
                    set<int>::iterator it = accu.lower_bound(tmpSum-k);
                    if(it != accu.end())
                        tmpMax = max(tmpMax, tmpSum-*it);
                    accu.insert(tmpSum);
                }
             
                if(tmpMax > maxSum)
                    maxSum = tmpMax;
            }
        }
        
        return maxSum;
    }
};