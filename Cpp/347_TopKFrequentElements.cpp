//min heap O(nlog(k))
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> count;
        priority_queue<int, vector<int>, greater<int>> max_k; //min heap
        for(int i = 0; i < nums.size(); ++i) {
            ++count[nums[i]];
        }
        for(auto & it : count) {
            max_k.push(it.second);
            if(max_k.size() > k)
                max_k.pop();
        }
        vector<int> res;
        for(auto &it : count) {
            if(it.second >= max_k.top()) {
                res.push_back(it.first);
            }
        }
        return res;
        
    }
};


//bucket sort O(n)
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> count;
        vector<vector<int>> bucket(nums.size()+1);
        for(int i = 0; i < nums.size(); ++i) {
            ++count[nums[i]];
        }
        for(auto it : count) {
            bucket[it.second].push_back(it.first);
        }
        reverse(bucket.begin(), bucket.end());
        vector<int> res;
        for(auto it_b : bucket) {
            for(int element : it_b) {
                res.push_back(element);
                if(res.size() == k) {
                    return res;
                }
            }
            
        }
        return res;
        
    }
};