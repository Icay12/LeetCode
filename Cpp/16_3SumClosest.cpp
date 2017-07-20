class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        //int result = 0;
        int minError = target - nums[0] - nums[1] - nums[2];
        for(int i = 0; i < (int)nums.size()-2; ++i) {

            if(i > 0 && nums[i] == nums[i-1]) {
                continue;
            }
            int target2 = target - nums[i];
            int j = i + 1, k = (int)nums.size() - 1;
            while(j < k) {
                int sumOfjk = nums[j] + nums[k];
                if(sumOfjk == target2) {
                    return target;
                }
                else if(sumOfjk > target2) {
                    if(abs(sumOfjk-target2) < abs(minError)) {
                        minError = target2 - sumOfjk;
                    }
                    --k;
                }
                else {
                    if(abs(sumOfjk-target2) < abs(minError)) {
                        minError = target2 - sumOfjk;
                    }
                    ++j;
                }
            }
        }
        return target - minError;
    }
};