class Solution {
public:
    bool judgePoint24(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        bool res = false;
        do {
            double a = nums[0], b = nums[1], c = nums[2], d = nums[3];
            res = calculate(a+b, c, d) || calculate(a*b, c, d) || calculate(a/b, c, d) || calculate(a-b, c, d) || 
                  calculate(a, b+c, d) || calculate(a, b*c, d) || calculate(a, b/c, d) || calculate(a, b-c, d) ||
                  calculate(a, b, c+d) || calculate(a, b, c*d) || calculate(a, b, c/d) || calculate(a, b, c-d);
        }while(!res && next_permutation(nums.begin(), nums.end()));
        return res;
            
            
    }
    
    bool calculate(double a, double b, double c) {
        return calculate(a+b, c) || calculate(a-b, c) || calculate(a*b, c) || b&&calculate(a/b, c) ||
                calculate(a, b+c) || calculate(a, b-c) || calculate(a, b*c) || c&&calculate(a, b/c);
    }
    
    bool calculate(double a, double b) {
        return abs(a+b-24)<0.001 || abs(a-b-24)<0.001 || abs(a*b-24)<0.001 || b&&abs(a/b-24)<0.001;
        // return ((a+b) == 24) || ((a-b) == 24) || ((a*b) == 24) || b&&((a/b) == 24);
    }
};