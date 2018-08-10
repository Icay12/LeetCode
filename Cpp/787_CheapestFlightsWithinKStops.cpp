//dp

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        if(src == dst)
            return 0;
        vector<vector<int>> dp(n, vector<int>(K+2, INT_MAX));
        //save the flights to a map
        unordered_map<int, unordered_map<int, int>> f;
        for(int i = 0; i < flights.size(); ++i) {
            f[flights[i][0]].insert({flights[i][1], flights[i][2]});
            
        }
        
        unordered_set<int> visited;
        
        dp[src][0] = 0;
        visited.insert(src);
        for(int j = 1 ; j <= K+1; ++j) {
            for(int i = 0; i < n; ++i) {
                for(int v : visited) {
                    if(v != i && dp[v][j-1] != INT_MAX && f.count(v)!=0 && f[v].count(i)!=0)
                        dp[i][j] = min(dp[i][j], dp[v][j-1]+f[v][i]);
                }
                if(dp[i][j] != INT_MAX && visited.find(i) == visited.end())
                    visited.insert(i);
            }
        }
        
        int res = INT_MAX;
        for(int i = 1; i <= K+1; ++i) {
            res = min(res, dp[dst][i]);
        }
        return res == INT_MAX? -1 : res;
    }
};



///bfs

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        if(src == dst)
            return 0;

        //save the flights to a map
        unordered_map<int, vector<pair<int, int>>> f;
        for(int i = 0; i < flights.size(); ++i) {
            f[flights[i][0]].push_back({flights[i][1], flights[i][2]});
            
        }

        queue<pair<int,int>> next;
        int level = 0;
        
        vector<int> minCost(n, INT_MAX);
        next.push({src,0});
        minCost[src] = 0;
        while(!next.empty() && level <= K) {
            int len = next.size();
            for(int i = 0; i < len; ++i) {
                pair<int,int> cur = next.front();
                next.pop();
                // cout << cur.first << endl;
                for(auto p : f[cur.first]) {
                    if(cur.second + p.second < minCost[p.first]) {
                        minCost[p.first] = cur.second + p.second;
                        next.push({p.first, minCost[p.first]});
                        // cout << p.first << endl;
                    }
                }
            }
            level++;
        } 
        
        return minCost[dst] == INT_MAX ? -1 : minCost[dst];
    }
};