class Solution {
public:
    int maxEnvelopes(vector<pair<int, int>>& envelopes) {
        if(envelopes.size() == 0)
            return 0;
        sort(envelopes.begin(), envelopes.end(), [](pair<int, int> a, pair<int, int> b){
            return a.first < b.first || (a.first == b.first && a.second > b.second);
        });
        
        vector<int> tail(envelopes.size(), 0);
        int len = 0;
        // cout << " 1 " << endl;
        for(pair<int,int> en : envelopes) {
            
            int pos = binarySearch(0, len, tail, en.second);
            if(pos == len) {
                tail[len] = en.second;
                len += 1;
            }
            else {
                tail[pos] = en.second;
            }
        }
        return len;   
    }
    
    int binarySearch(int begin, int len, vector<int>& tail, int k) {
        int end = begin + len - 1;
        while(begin <= end) {
            int mid = (begin + end) / 2;
            if(k == tail[mid]) {
                // cout << mid << endl;
                return mid;
            }
            else if(k > tail[mid]) {
                begin = mid + 1;
            }
            else if(k < tail[mid]) {
                end = mid - 1;
            }
                
        }
        // cout << begin << endl;
        return begin;
    }
};