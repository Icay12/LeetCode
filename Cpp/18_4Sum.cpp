class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> result;
        for(int i = 0; i < (int)nums.size()-3; ++i) {
            if(i > 0 && nums[i] == nums[i-1]) {
                continue;
            }
            for(int j = i+1; j < (int)nums.size()-2; ++j) {
                if(j > i+1 && nums[j] == nums[j-1]) {
                    continue;
                }
                int target2 = target - nums[i] - nums[j];
                int k = j+1, z = (int)nums.size() - 1;
                while(k < z) {
                    int sumOfkz = nums[k] + nums[z];
                    if(sumOfkz == target2) {
                        vector<int> quadruplets(4,0);
                        quadruplets[0] = nums[i];
                        quadruplets[1] = nums[j];
                        quadruplets[2] = nums[k];
                        quadruplets[3] = nums[z];
                        result.push_back((quadruplets));
                        ++k;
                        --z;
                        while(k < z && nums[k] == nums[k-1]) ++k;
                        while(k < z && nums[z] == nums[z+1]) --z;
                    }
                    else if(sumOfkz > target2) {
                        --z;
                    }
                    else {
                        ++k;
                    }
                }
            }
        }
        return result;
    }
};