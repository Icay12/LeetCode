
// use another array
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        if(n == 0 || k <= 0)
            return;
        vector<int> nums2(nums.size(), 0);
        for(int i = 0; i < nums.size(); ++i) {
            nums2[i] = nums[i];
        }
        for(int i = 0; i < nums.size(); ++i) {
            nums[(i+k)%n] = nums2[i];
        }
        return;
    }
};


// use three reverse
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        if(n == 0 || k <= 0)
            return;
        k = k % n;
        reverse(nums.begin(), nums.begin()+n-k);
        reverse(nums.begin()+n-k, nums.end());
        reverse(nums.begin(), nums.end());
    }
};


//rotate

 
// use another array
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;
        if(n == 0 || k <= 0)
            return;
        
        int cur = 0;
        int cnt = 0;
        int start = 0;
        int valtorotate = nums[0];
        int tmp;
        while(cnt < n) {
            do{
                tmp = nums[(cur+k)%n];
                nums[(cur+k)%n] = valtorotate;
                valtorotate = tmp;
                cur = (cur+k)%n;
                cnt++;
            }while(cur != start);
            start++;
            cur = start;
            valtorotate = nums[cur];
        }
    }
};

