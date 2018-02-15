class Solution {
public:
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size();
        int m = nums2.size();
        vector<int> res(k,0);
        for(int i = max(0,k-m); i <= k && i <= n ; ++i) {
            vector<int> nums1k = maxArray(nums1,i);
            vector<int> nums2k = maxArray(nums2,k-i);
            vector<int> ires = merge(nums1k,nums2k,k);
            if(isGreater(ires,0, res,0)) {
                res = ires;
            }
        }
        return res;
    }

    vector<int> merge(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<int> newnums(k);
        int n = nums1.size();
        int m = nums2.size();
        int cnt1 = 0, cnt2 = 0;
        for(int i = 0; i < k; ++i) {
//             if(cnt1 < n && cnt2 < m) {
//                 if(nums1[cnt1] > nums2[cnt2]) {
//                     newnums[i] = nums1[cnt1];
//                     cnt1++;
//                 }
//                 else {
//                     newnums[i] = nums2[cnt2];
//                     cnt2++;
//                 }

//             }
//             else if(cnt1 < n) {
//                 newnums[i] = nums1[cnt1];
//                 cnt1++;
//             }
//             else {
//                 newnums[i] = nums2[cnt2];
//                 cnt2++;
//             }
            if(isGreater(nums1,cnt1,nums2,cnt2)) {   //[6,7] [6,0,4]
                newnums[i] = nums1[cnt1];
                cnt1++;
            }
            else {
                newnums[i] = nums2[cnt2];
                cnt2++;
            }
        }
        return newnums;
    }

    vector<int> maxArray(vector<int>& nums, int k) {
        int j = 0;
        int n = nums.size();
        vector<int> res(k, 0);
        for(int i = 0; i < n; ++i) {
            while(n - i >= k - j + 1 && j > 0 && nums[i] > res[j-1])
                --j;
            if(j < k) {   ////////notice here, because k can be 0
                res[j] = nums[i];
                ++j;
            }

        }
        return res;
    }

    bool isGreater(vector<int>& nums1, int n1, vector<int>& nums2, int n2) {
        while(n1 < nums1.size() && n2 < nums2.size() && nums1[n1] == nums2[n2]) {
            n1++, n2++;
        }
        if(n2 == nums2.size())
            return true;
        if(n1 != nums1.size() && nums1[n1] > nums2[n2])
            return true;
        return false;
    }
};
