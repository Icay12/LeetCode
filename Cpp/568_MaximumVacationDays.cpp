//consider test cases
//case 1: 
// [[0,1,0],[0,0,0],[0,0,0]]
// [[0,0,7],[2,0,0],[7,7,7]]


//case 2:
// [[0,0,0],[0,0,0],[0,0,0]]
// [[1,0,],[7,7,7],[7,7,7]]

class Solution {
public:
    int maxVacationDays(vector<vector<int>>& flights, vector<vector<int>>& days) {
        int N = flights.size();
        int K = days[0].size();
        vector<vector<int>> dp(N, vector<int>(K, 0));
        vector<bool> canReach(N, false);
        int res = 0;
        
        for(int j = 0; j < K; ++j) {
            for(int i = 0; i < N; ++i) {
                if(j == 0 && i == 0) {
                    dp[i][j] = days[0][0];
                    canReach[i] = true;
                }
                else if(j == 0 && i != 0) {
                    dp[i][j] = days[i][0]*flights[0][i];
                    if(flights[0][i])
                        canReach[i] = true;
                }
                else { // j > 0
                    for(int x = 0; x < N; ++x) {
                        if(!canReach[x]) //can not reach city x before
                            continue;
                        // cout << x << endl;
                        if(x == i) {
                            dp[i][j] = max(dp[i][j], days[i][j] + dp[i][j-1]);
                        }
                        else if(flights[x][i] != 0){ //can reach city i from x
                            dp[i][j] = max(dp[i][j], days[i][j]*flights[x][i] + dp[x][j-1]);
                            canReach[i] = true;
                        }
                    }
                }
                if(j == K - 1)
                    res = max(dp[i][j], res);
            }
        }
        return res;
    }
};