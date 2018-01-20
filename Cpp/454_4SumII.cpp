class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        int result = 0;
        unordered_map<int, int> abSum;
        for(int a = 0; a < A.size(); ++a) {
            for(int b = 0; b < B.size(); ++b) {
                ++abSum[A[a]+B[b]];
            }
        }
        for(int c = 0; c < C.size(); ++c) {
            for(int d = 0; d < D.size(); ++d) {
                if(abSum.find(-C[c]-D[d]) != abSum.end()) {
                    result+= abSum[-C[c]-D[d]];
                }
            }
        }
        return result;
    }
};