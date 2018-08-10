class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> res;
        if(n == 0)
            return res;
        set<int> trueSet;
        vector<bool> visited(n, false);
        
        for(int i = 0; i < n; ++i) {
            
            if(!visited[i])
                dfs(graph,visited,i,trueSet);
        }
        
        
        for(int a : trueSet) {
            res.push_back(a);
        }
        return res;
    }
    
    bool dfs(vector<vector<int>> &graph, vector<bool> &visited, int start, set<int> &trueSet) {
        if(trueSet.find(start) != trueSet.end()) {
            return true;
        }
        if(visited[start] && trueSet.find(start) == trueSet.end()) {
            // falseSet.insert(start);
            // cout << "insert " << start << endl;
            return false;
        }
        visited[start] = true;
        bool flag = true;
        
        for(int a : graph[start]) {

            if(!dfs(graph,visited, a, trueSet)) {
                // falseSet.insert(start);
                // cout << "insert " << start << endl;
                flag = false;
            }
        }
        if(flag)
            trueSet.insert(start);
        
        return flag;
        
    }
};