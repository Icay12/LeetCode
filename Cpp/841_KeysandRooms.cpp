class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<bool> visited(rooms.size(), false);
        dfs(rooms, visited, 0);
        for(auto a : visited) {
            if(!a) {
                return false;
            }
        }
        return true;
    }
    
    void dfs(vector<vector<int>>& rooms, vector<bool>& visited, int r) {
        if(visited[r])
            return;
        
        visited[r] = true;
        
        if(rooms[r].size() == 0)
            return;
        
        for(int key : rooms[r]) {
            dfs(rooms, visited, key);
        }
    }
};