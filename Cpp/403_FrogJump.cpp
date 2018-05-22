class Solution {
public:
    bool canCross(vector<int>& stones) {
        if(stones.size() == 0 && stones[0] != 0 )
            return false;
        if(stones.size() == 1)
            return true;
        if(stones[1] != 1)
            return false;
        unordered_set<int> memo;
        for(int i = 0; i < stones.size(); ++i) {
            if(i > 3 && stones[i] > stones[i-1] * 2)
                return false;
            memo.insert(stones[i]);
        }
        return cross(stones, memo, 0, 1);
    }

    bool cross(vector<int>& stones, unordered_set<int>& memo, int pos, int step) {
        if(pos == stones.back())
            return true;
        if(memo.find(pos+step) != memo.end()) {
            for(int i = step+1; i >= step-1 && i > 0; --i) {
                if(cross(stones, memo, pos+step, i))
                    return true;
            }
        }
        return false;
    }
};