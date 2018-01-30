class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<int> bottom = triangle.back();
        for(int i = (int)triangle.size() - 1; i > 0; --i) {
            for(int j = 0; j < i; ++j) {
                bottom[j] = min(bottom[j],bottom[j+1]) + triangle[i-1][j];
            }
            
        }
        return bottom[0];
    }
};