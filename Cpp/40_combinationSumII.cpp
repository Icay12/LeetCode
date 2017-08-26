class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> combination;
        vector<vector<int>> res;
        if(candidates.empty())
            return res;
        solveSum(candidates, target, res, combination,0);
        return res;
    }
    void solveSum(vector<int>& candidates, int target, vector<vector<int>>& res, vector<int>&combination,int begin) {
        if(target == 0) {
            res.push_back(combination);
            return;
        }
        if(target < 0) 
            return;
        for(int i = begin; i < candidates.size() && candidates[i] <= target; ++i) {
            if(i > begin && candidates[i] == candidates[i-1])
                continue;
            combination.push_back(candidates[i]);
            solveSum(candidates,target-candidates[i],res,combination,i+1);
            combination.pop_back();
        }
    }
};