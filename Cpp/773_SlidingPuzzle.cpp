//bfs

class Solution {
    unordered_map<int, vector<int>> iSwap = { {0, {1,3}}, {1,{2,0,4}}, {2,{1,5}}, {3,{0,4}},{4,{1,3,5}},{5,{2,4}} };
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        string bd = to_string(board[0][0])+to_string(board[0][1])
                    +to_string(board[0][2])+to_string(board[1][0])+to_string(board[1][1])+to_string(board[1][2]);
        
        unordered_set<string> visited;
        queue<string> nextLevel;
        int level = 0;
        
        nextLevel.push(bd);
        while(!nextLevel.empty()) {
            int n = nextLevel.size();
            for(int i = 0; i < n; ++i) {
                string cur = nextLevel.front();
                if(cur == "123450")
                    return level;
                int cur0 = cur.find('0');
                nextLevel.pop();
                for(int a : iSwap[cur0]) {
                    string tmp = cur;
                    swap(tmp[cur0],tmp[a]);
                    if(visited.find(tmp) == visited.end()) {
                        nextLevel.push(tmp);
                        visited.insert(tmp);
                    }
                }
                
            }
            level++;
        }
        return -1;
        
    }
    
};