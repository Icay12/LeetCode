class Solution {
public:
    int compareVersion(string version1, string version2) {
        int nums1 = 0;
        int nums2 = 0;
        int len1 = version1.length();
        int len2 = version2.length();
        int i = 0, j = 0;
        while(i < len1 || j < len2) {
            while(i < len1 && version1[i] != '.') {
                nums1 = nums1*10 + (version1[i]-'0');
                ++i;
            }
            while(j < len2 && version2[j] != '.') {
                nums2 = nums2*10 + (version2[j]-'0');
                ++j;
            }
            if(nums1 > nums2)
                return 1;
            if(nums1 < nums2)
                return -1;
            ++i, ++j;
            nums1 = 0;
            nums2 = 0;
        }
        return 0;
    }
};