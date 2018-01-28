//recursive

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int len = nums.size();
        vector<vector<int>> res;
        vector<int> sub;
        gensubsets(nums,res,0,sub);
        return res;
    }
    void gensubsets(vector<int>& nums, vector<vector<int>>& res, int begin, vector<int>& sub) {
        res.push_back(sub);
        for(int i = begin; i < nums.size(); ++i) {
            sub.push_back(nums[i]);
            gensubsets(nums,res,i+1,sub);
            sub.pop_back();
        }
        return;
    }
};

//iteration

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> sub;
        res.push_back(sub);
        for(int i = 0; i < nums.size(); ++i) {
            
            int len = res.size();
            for(int j = 0; j < len; ++j) {
                sub = res[j];
                sub.push_back(nums[i]);
                res.push_back(sub);
            }
        }
        return res;
        
    }
};


//bit

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int len = pow(2,nums.size());
        vector<vector<int>> res(len,vector<int>());
        for(int i = 0; i < nums.size(); ++i) {
            for(int j = 0; j < len; ++j) {
                if((j >> i) & 1)
                    res[j].push_back(nums[i]);
            }
        }
        return res;
    }
};