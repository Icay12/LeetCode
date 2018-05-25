class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        int maxnum = nums[0];
        int sum = 0;
        for(int num : nums) {
            sum += num;
            maxnum = maxnum > num ? maxnum : num;
        }
        if(m == 1)
            return sum;
        int l = maxnum;
        int r = sum;
        while(l <= r) {
            int mid = l + ((r - l) >> 1);
            if(valid(mid, nums, m)) {
                r = mid - 1;
            }
            else {
                l = mid + 1;
            }
        }
        return l;
    }
    
    bool valid(int target, vector<int>& nums, int m) {
        int count = 1;
        int total = 0;
        for(int num : nums) {
            total += num;
            if(total > target) {
                total = num;
                count += 1;
                if(count > m) {
                    return false;
                }
            }
        }
        return true;
    }
};

//trie TLE

class Solution {
private:
    vector<int> trie;
public:
    int splitArray(vector<int>& nums, int m) {

        trie = vector<int>(nums.size() + 1, 0);
        for(int i = 0; i < nums.size(); ++i) {
            insertTrie(i, nums[i]);
        }
        if(m == 1)
            return sumTrie((int)nums.size()-1);
        return split(nums, m, 0);
    }

    int split(vector<int>& nums, int m, int begin) {
        if(m == 1)
            return sumTrie((int)nums.size()-1) - sumTrie(begin-1);
        int maxsum = INT_MAX;
        for(int i = begin; i < (nums.size()- m + 1); ++i) {
            int thissum = sumTrie(i) - sumTrie(begin-1);
            int tmpmaxsum = max(split(nums, m-1, i+1), sumTrie(i) - sumTrie(begin-1));
            maxsum = min(maxsum, tmpmaxsum);
        }
        return maxsum;
    }

    void insertTrie(int index, int val) {
        index += 1;
        while(index < trie.size()) {
            trie[index] += val;
            index += index & (-index);
        }
    }

    int sumTrie(int index) {
        int sum = 0;
        index += 1;
        while(index > 0) {
            sum += trie[index];
            index -= index & (-index);
        }
        return sum;
    }
};