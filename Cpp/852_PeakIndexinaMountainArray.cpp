class Solution {
public:
    int peakIndexInMountainArray(vector<int>& A) {
        int begin = 0;
        int end = (int)A.size() - 1;
        
        while(begin <= end) {
            int mid = begin + ((end - begin) >> 1);
            if(A[mid] > A[mid-1] && A[mid] > A[mid+1]) {
                return mid;
            }
            else if(A[mid] < A[mid+1]) {
                begin = mid+1;
            }
            else {
                end = mid-1;
            }
        }
        return begin;
    }
};