class Solution {
public:
    vector<double> calcEquation(vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> queries) {
        unordered_map< string, unordered_map<string,double> > hash;
        int cnt = 0;
        //estabilish the graph
        for(auto p : equations) {
            hash[p.first][p.second] = values[cnt];
            hash[p.second][p.first] = 1.0/values[cnt++];
            hash[p.first][p.first] = 1.0;
            hash[p.second][p.second] = 1.0;
        }
        vector<double> res;
        for(auto p : queries) {
            bool find = false;
            unordered_set<string> visited;
            double d = dfs(hash, p.first,p.second, visited, 1.0, find);
            res.push_back(d);
        }
        
        return res;
    }

    double dfs(unordered_map< string, unordered_map<string,double> > &hash, string i, string j, unordered_set<string> &visited, double value, bool &find) {
        //have visited
        if(visited.find(i) != visited.end())
            return -1.0;
        visited.insert(i);
        //have not visited
        //find j
        if(hash[i].count(j) != 0) {
            find = true;
            return value*hash[i][j];
        }
        else {
            for(auto p : hash[i]) {
                double r = dfs(hash, p.first, j, visited, p.second*value,find);
                if(find)
                    return r;
            }
        }
        return -1.0;
    }
};