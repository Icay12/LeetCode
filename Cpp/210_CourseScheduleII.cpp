//dfs
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<unordered_set<int>> graph(numCourses);
        vector<int> res;
        //make graph
        for(auto pre : prerequisites) {
            graph[pre.second].insert(pre.first);
        }
        
        vector<bool> visited(numCourses);
        vector<bool> oneVisit(numCourses);
        
        for(int i = 0; i < numCourses; ++i) {
            if(!visited[i] && !dfs(graph, i, visited, oneVisit, res))
                return {};
        }
        
        reverse(res.begin(), res.end());
        return res;
    }
            
    bool dfs(vector<unordered_set<int>>& graph, int i, vector<bool>& visited, vector<bool>& oneVisit, vector<int>& res) {
        if(visited[i])
            return true;
        visited[i] = true;
        oneVisit[i] = true;
        // cout << "visit" << i << endl;
        for(int n : graph[i]) {
            if( oneVisit[n] || !dfs(graph, n, visited, oneVisit, res)) {
                return false;
            }
        }
        // no successive node
        res.push_back(i);
        // cout << i << endl;
        oneVisit[i] = false;
        return true;
    }
    
};


//bfs topological sort

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<unordered_set<int>> graph(numCourses);
        vector<int> res;
        vector<int> indegree(numCourses,0);
        //make graph
        for(auto pre : prerequisites) {
            graph[pre.second].insert(pre.first);
            indegree[pre.first]++;
        }

        for(int i = 0; i < numCourses; ++i) {
            int j = 0;
            for(; j < numCourses; ++j) {
                if(indegree[j] == 0)
                    break;
            }
            if(j == numCourses)
                return {};
            indegree[j] = -1;
            for(int n : graph[j]) {
                indegree[n]--;
            }
            res.push_back(j);
        }
        
        return res;
    }

    
};