
//DFS check cycle
class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<unordered_set<int>> graph(numCourses);
        //make graph
        for(auto pre : prerequisites) {
            graph[pre.second].insert(pre.first);  
            // cout << pre.second << " insert " << pre.first << endl;
        }
        
        vector<bool> visited(numCourses, false);
        vector<bool> onevisit(numCourses, false);
        
        for(int i = 0; i < numCourses; ++i) {
            //not visited, visit it
            if(!visited[i] && !dfs(graph, i, visited, onevisit))
                    return false;
        }
        return true;
        
    }
    
    
    bool dfs(vector<unordered_set<int>>& graph, int node, vector<bool>& visited, vector<bool> onevisit) {
        // if(onevisit[node])
        //     return false;
        if(visited[node])
            return true;
        visited[node] = onevisit[node] = true;
        for(int i : graph[node]) {
            if( onevisit[i] || !dfs(graph, i, visited, onevisit))
                return false;
        }
        onevisit[node] = false;
        return true;
    }
    
    
};


//BFS topological sort

class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<unordered_set<int>> graph(numCourses);
        vector<int> indegree(numCourses, 0);
        //make graph
        for(auto pre : prerequisites) {
            graph[pre.second].insert(pre.first);  
            indegree[pre.first]++;
        }
        
        //at most numCourses times
        for(int i = 0; i < numCourses; ++i) {
            int j = 0;
            //fine a node whose indegree = 0
            for(; j < numCourses; ++j) {
                if(indegree[j] == 0)
                    break;
            }
            // if no such node
            if(j == numCourses)
                return false;
            indegree[j] = -1;
            for(int n : graph[j]) {
                indegree[n]--;
            }
        }
        return true;
        
    }
    
    
    
};