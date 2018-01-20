class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        unordered_map<int, int> hashMap;
        vector<int> result; 
        for(int i = 0; i < numbers.size(); ++i) {
            if(hashMap.find(target-numbers[i]) != hashMap.end()) {
                result.push_back(hashMap[target-numbers[i]]+1);
                result.push_back(i+1);
            }
            else {
                hashMap[numbers[i]] = i;
            }
        }
        return result;
    }
};