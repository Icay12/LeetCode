class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int a = m-1, b = n-1;
        for(int k = m+n-1; k >= 0; --k) {
            if(a >= 0 && b >= 0) {
                if(nums1[a] >= nums2[b]) {
                    nums1[k] = nums1[a];
                    --a;
                }
                else {
                    nums1[k] = nums2[b];
                    --b;
                } 
            }
            else if(a >= 0) {
                nums1[k] = nums1[a];
                --a;
            }
            else {
                nums1[k] = nums2[b];
                --b;
            }
        }
    }
};