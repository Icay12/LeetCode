#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        if (m > n) {
            return findMedianSortedArrays(nums2, nums1);
        }

        //assume A[0] A[1] ... A[i-1]  |  A[i] ... A[m-1]
        //assume B[0] B[1] ... B[j-1]  |  B[j] ... B[n-1]
        //so i + j == m - i + n - j
        int min_i = 0;
        int max_i = m;
        int i, j;

        //int  = (m + n + 1) / 2;  // +1 in case there are odd numbers

        //binary search
        while(min_i <= max_i) {     // < or ==
            i = (min_i + max_i) / 2;
            j = (m + n + 1 - i * 2) / 2; // +1 in case there are odd numbers

            if(i < m && nums2[j - 1] > nums1[i]) {
                min_i += 1;
            } else if(i > 0 && nums1[i - 1] > nums2[j]) {
                max_i -= 1;
            } else {
                //i == 0 || i == m || A[i-1] < B[j] && A[i] > B[j-1]
                double left, right;
                if(i == 0) {
                    left = nums2[j - 1];
                } else if(j == 0) {
                    left = nums1[i - 1];
                } else {
                    left = max(nums1[i-1], nums2[j-1]);
                }
                //odd numbers
                if((m + n) % 2 == 1) {
                    return left;
                }

                if(i == m) {
                    right = nums2[j];
                }
                else if(j == n) {
                    right = nums1[i];
                }
                else {
                    right = min(nums1[i], nums2[j]);
                }

                return (left + right)/2;
            }
        }
    }
};

int main() {
    int array1[] = {1,2};
    int array2[] = {3,4,5,6};
    vector<int> nums1(2);
    int s1 = nums1.size();
    vector<int> nums2(4);

    for(int i=0; i < 2; ++i) {
        nums1[i] = array1[i];
    }
    for(int i=0; i < 4; ++i) {
        nums2[i] = array2[i];
    }
    Solution S;
    double result = S.findMedianSortedArrays(nums1,nums2);
    cout << result << endl;
    return 0;
}
