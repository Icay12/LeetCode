class Solution {
public:
    int kEmptySlots(vector<int>& flowers, int k) {
        vector<int> days(flowers.size());
        for(int i = 0; i < flowers.size(); ++i) {
            days[flowers[i]-1] = i+1;
        }
        
        int res = INT_MAX;
        int begin = 0, end = begin+k+1;
        for(int i = 1; end < flowers.size(); ++i) {
            if(i == end) {
                res = min(res,max(days[begin], days[end]));
                begin = i;
                end = begin+k+1;
            }
            if(days[i] > days[begin] && days[i] > days[end]) {
                continue;
            }
            else {
                begin = i;
                end = begin+k+1;
            }
        }
        return res == INT_MAX? -1 : res;
    }
};