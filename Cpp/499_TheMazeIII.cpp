class Solution {
    const vector<int> dirx = {1,-1,0,0};
    const vector<int> diry = {0,0,1,-1};
    const vector<string> dir = {"d","u","r","l"};
public:
    string findShortestWay(vector<vector<int>>& maze, vector<int>& ball, vector<int>& hole) {
        // if(ball[0] == hole[0] && ball[1] == hole[1])
        //     return "";
        int m = maze.size(), n = maze[0].size();
        vector<vector<string>> visitPath(m, vector<string>(n, ""));
        vector<vector<int>> distance(m, vector<int>(n, -1));
        distance[ball[0]][ball[1]] = 0;
        dfs(maze, visitPath, distance,ball, hole);
        // cout << visitPath[hole[0]][hole[1]] << endl;
        return visitPath[hole[0]][hole[1]] == "" ? "impossible" : visitPath[hole[0]][hole[1]];
    }
    
    void dfs(vector<vector<int>>& maze, vector<vector<string>>& visitPath, vector<vector<int>>& distance,vector<int>& ball, vector<int>& hole) {
        if(ball[0] == hole[0] && ball[1] == hole[1]) {
            // cout << visitPath[hole[0]][hole[1]] << endl;
            return;
        }
            
        // try 4 directions
        int m = maze.size(), n = maze[0].size();
        
        for(int i = 0; i < 4; ++i) {
            string path = visitPath[ball[0]][ball[1]];
            int dis = distance[ball[0]][ball[1]];
            int newX = ball[0], newY = ball[1];
            path += dir[i];
            // cout << "a " << path << endl;
            while(newX+dirx[i] >= 0 && newX+dirx[i] < m && newY + diry[i] < n && newY+diry[i]>=0 &&
                  !maze[newX+dirx[i]][newY+diry[i]]) {
                // path += dir[i];
                dis++;
                if(newX+dirx[i] == hole[0] && newY + diry[i] == hole[1]) {
                    if(distance[hole[0]][hole[1]] == -1 || distance[hole[0]][hole[1]] > dis || (distance[hole[0]][hole[1]] == dis && visitPath[hole[0]][hole[1]] > path)) {
                        visitPath[hole[0]][hole[1]] = path;
                        distance[hole[0]][hole[1]] = dis;
                        // cout << visitPath[hole[0]][hole[1]] << endl;
                    }
                        
                    return;
                } 
                newX += dirx[i], newY += diry[i]; 
            }
            if(distance[newX][newY] >= 0 && (distance[newX][newY] < dis || distance[newX][newY] == dis&&visitPath[newX][newY]< path))
                continue;
            vector<int> newStart = {newX, newY};
            visitPath[newX][newY] = path;
            distance[newX][newY] = dis;
            // cout << "p " << path << endl;
            dfs(maze,visitPath,distance,newStart, hole);

        }
    }
};