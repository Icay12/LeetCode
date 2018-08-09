class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int S, int T) {
        if(S == T)
            return 0;
        unordered_map<int, vector<int>> stops;
        for(int i = 0; i < routes.size(); ++i) {
            for(int j : routes[i]) {
                stops[j].push_back(i);
            }
        }
        
        unordered_set<int> visited_stop;
        unordered_set<int> visited_bus;
        queue<int> q;
        q.push(S);
        
        //BFS
        int level = 0;
        while(!q.empty()) {
            int n = q.size();
            for(int i = 0; i < n; ++i) {
                int cur_stop = q.front();
                q.pop();
                
                //for each bus
                for(auto a : stops[cur_stop]) {
                    if(visited_bus.find(a) != visited_bus.end())
                        continue;
                    visited_bus.insert(a);
                    // cout<< "bus: " << a << endl;
                    //for each stop
                    for(auto b : routes[a]) {
                        if(visited_stop.find(b) == visited_bus.end()) {
                            if(b == T)
                                return level+1;
                            visited_stop.insert(b);
                            // cout<< "stop: " << b << endl;
                            q.push(b);
                        }
                    }
                }
            }
            ++level;
        }
        return -1;
    }
};