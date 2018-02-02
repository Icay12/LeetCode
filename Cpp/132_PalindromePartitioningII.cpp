class Solution {
public:
    int minCut(string s) {
        int n = s.length();
        vector<int> cuts(n);
        vector<vector<int>> isPal(n, vector<int>(n,false));
        for(int i = n-1; i >= 0; --i) {
            cuts[i] = n-1-i;
            for(int j = i; j < n; ++j) {
                int thisCut;
                if(s[i] == s[j] && (j - i < 2 || isPal[i+1][j-1])) {
                    if(j == n-1)
                        thisCut = 0;
                    else
                        thisCut = 1 + cuts[j+1];
                    isPal[i][j] = true;
                }
                else {
                    isPal[i][j] = false;
                    thisCut = cuts[i+1] + 1;
                }
                cuts[i] = min(cuts[i], thisCut);
            }
        }
        return cuts[0];
    }
};