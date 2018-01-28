class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.size() == 0 || matrix[0].size() == 0)
            return false;
        int m = matrix.size();
        int n = matrix[0].size();
        int left = 0, right = m*n-1;
        while(left <= right) {
            int mid = (right+left)/2;
            int midvalue = matrix[mid/n][mid%n];
            if(midvalue == target)
                return true;
            else if(midvalue > target) {
                right = mid - 1;
            }
            else {
                left = mid + 1;
            }
        }
        return false;
    }
};