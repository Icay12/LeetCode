class Solution {
public:
    int shortestDistance(vector<vector<int>>& grid) {
        //assume grid's size > 0
        int m = grid.size();
        int n = grid[0].size();
        
        //the distance for an 0 to all 1's
        vector<vector<int>> totalDistance(m, vector<int>(n,0));
        //if an 0 has been visited from each 1
        vector<vector<int>> visited(m, vector<int>(n,0));
        
        int cntHouse = 0;
        
        //calculate total distance
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                if(grid[i][j] == 1) {
                    cntHouse++;
                    //bfs
                    //level = distance
                    queue<pair<int,int>> nextLevel;
                    int level = 0;
                    nextLevel.push({i,j});
                    
                    //visit next level
                    while(!nextLevel.empty()) {
                        int s = nextLevel.size();
                        for(int k = 0; k < s; ++k) {
                            auto a = nextLevel.front();
                            nextLevel.pop();
                            if(level != 0)
                                totalDistance[a.first][a.second]+=level;
                        
                            if(a.first - 1 >= 0 && grid[a.first-1][a.second] == 0 && visited[a.first-1][a.second] == cntHouse-1) {
                                nextLevel.push({a.first-1,a.second});
                                visited[a.first-1][a.second]++;
                            }
                            if(a.first + 1 < m && grid[a.first+1][a.second] == 0 && visited[a.first+1][a.second] == cntHouse-1) {
                                nextLevel.push({a.first+1,a.second});
                                visited[a.first+1][a.second]++;
                            }
                            if(a.second - 1 >= 0 && grid[a.first][a.second-1] == 0 && visited[a.first][a.second-1] == cntHouse-1) {
                                nextLevel.push({a.first,a.second-1});
                                visited[a.first][a.second-1]++;
                            }
                            if(a.second + 1 < n && grid[a.first][a.second+1] == 0 && visited[a.first][a.second+1] == cntHouse-1) {
                                nextLevel.push({a.first,a.second+1});
                                visited[a.first][a.second+1]++;
                            }
                        
                            
                        }
                        level++;
                        
                    }
                    
                    
                }
            }
        }
        
        int res = -1;
        //find shortest distance
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                //if 0 and have access to all houses
                if(visited[i][j] == cntHouse)
                    res = (res == -1? totalDistance[i][j] : min(res, totalDistance[i][j]));
            }
        }
        return res;
     }
};