class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int res = 0;

        int valueMax = INT_MIN;
        for(int i = 0; i < arr.size(); ++i) {

            valueMax = max(valueMax, arr[i]);
            if(valueMax == i) {
                res++;
                valueMax = INT_MIN;
            }

        }
        return res;
    }
};