class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        int n = A.size();
        for(int i = 0; i < n; ++i) {
            int begin = 0;
            int end = n-1;
            while(begin < end) {
                A[i][begin] = 1 - A[i][begin];
                A[i][end] = 1 - A[i][end];
                swap(A[i][begin], A[i][end]);
                begin++;
                end--;
            }
            if(begin == end)
                A[i][begin] = 1 - A[i][begin];
        }
        return A;
    }
};