class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int num1 = 0;
        int cnt1 = 0;
        int num2 = 1; // so that num1 and num2 cannot be the same : case [0,0,0]
        int cnt2 = 0;

        for(int a : nums) {
            
            if(a == num1) {
                cnt1++;
            }
            else if(a == num2) {
                cnt2++;
            }
            else if(cnt1 == 0) {
                num1 = a;
                cnt1++;
            }
            else if(cnt2 == 0) {
                num2 = a;
                cnt2++;
            }
            else {
                cnt1--;
                cnt2--;
            }
                
        }
        
        cnt1 = 0, cnt2 = 0;
        for(int a : nums) {
            if(a == num1)
                cnt1++;
            if(a == num2)
                cnt2++;
        }
        vector<int> res;
        int n = nums.size();
        if(cnt1 > n/3) 
            res.push_back(num1);
        if(cnt2 > n/3)
            res.push_back(num2);
        return res;
        
    }
};