class Solution {
public:
    int intersectionSizeTwo(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](vector<int> a, vector<int> b) {
            return a[1] < b[1] || (a[1] == b[1] && a[0] > b[0]);
        });
        
        int ans = 0, max1 = -1, max2 = -1;
        for(auto i : intervals) {
            // cout << i[0] << " " << i[1] << "---";
            if(i[0] > max1) {
                ans += 2;
                max1 = i[1];
                max2 = i[1]-1;
                // cout << max1 << " " << max2 << endl;
            }
            else if(i[0] > max2) {
                ans += 1;
                max2 = max1;
                max1 = i[1];
                // cout << max1<< endl;
            }
        }
        return ans;
    }
};