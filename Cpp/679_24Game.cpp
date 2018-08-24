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


//backtracking

class Solution {
public:
    bool judgePoint24(vector<int>& nums) {
        vector<double> newNums(nums.begin(), nums.end());
        return helper(newNums);  
    }
    
    bool helper(vector<double>& nums) {
        if(nums.size() == 1) {
            if(abs(nums[0] - 24) < 0.001)
                return true;
            else
                return false;
        }
        
        for(int i = 0; i < nums.size(); ++i) {
            for(int j = i + 1; j < nums.size(); ++j) {
                vector<double> newNum;
                for(int k = 0; k < nums.size(); ++k) {
                    if(k == i || k == j) {
                        continue;
                    }
                    newNum.push_back(nums[k]);
                }
                
                // try + - * /
                newNum.push_back(nums[i]+nums[j]);
                if(helper(newNum))
                    return true;
                newNum.pop_back();
                
                newNum.push_back(nums[i]-nums[j]);
                if(helper(newNum))
                    return true;
                newNum.pop_back();
                
                newNum.push_back(nums[j]-nums[i]);
                if(helper(newNum))
                    return true;
                newNum.pop_back();
                
                newNum.push_back(nums[i]*nums[j]);
                if(helper(newNum))
                    return true;
                newNum.pop_back();
                
                if(abs(nums[j]) >= 0.001) {
                    newNum.push_back(nums[i]/nums[j]);
                    if(helper(newNum))
                        return true;
                    newNum.pop_back();
                }
                
                if(abs(nums[i]) >= 0.001) {
                    newNum.push_back(nums[j]/nums[i]);
                    if(helper(newNum))
                        return true;
                    newNum.pop_back();
                }
                
            }
        }
          
        return false;
            
    }

};