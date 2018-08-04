class Solution {
    const vector<int> dirx = {1,-1,0,0};
    const vector<int> diry = {0,0,1,-1};
public:
    bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        int m = maze.size();
        int n = maze[0].size();
        //should near a wall
        int dx = destination[0], dy = destination[1];
        if(dx - 1 >= 0 && dx + 1 < m && dy - 1 >= 0 && dy+ 1 < n && !maze[dx-1][dy] && !maze[dx+1][dy] && !maze[dx][dy-1] && !maze[dx][dy+1])
            return false;
        // cout << 1 << endl;
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        // cout << 2 << endl;
        return dfs(maze,start, destination, visited);
        
    }
    
    bool dfs(const vector<vector<int>>& maze, vector<int> start, const vector<int>& destination,vector<vector<bool>>& visited) {
        if(start[0] == destination[0] && start[1] == destination[1]) {
            return true;
        }
        visited[start[0]][start[1]] = true;
        
        //visit every empty direction
        for(int i = 0; i < 4; ++i) {
            vector<int> newstart(2, 0);
            int sx = start[0], sy = start[1];
            while(sx+dirx[i]>=0 && sx+dirx[i]<maze.size() && sy+diry[i]<maze[0].size() && sy+diry[i]>=0 && !maze[sx+dirx[i]][sy+diry[i]]) {
            sx = sx+dirx[i];
            sy = sy+diry[i];
        }    
            if(!visited[sx][sy]) {
                newstart[0] = sx;
                newstart[1] = sy;
                if(dfs(maze,newstart,destination, visited))
                    return true;
            }
        }

        return false;
    }
};