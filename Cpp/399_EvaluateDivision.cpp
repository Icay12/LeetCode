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



//bfs

class Solution {
public:
    vector<double> calcEquation(vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> queries) {
        //key: variable
        //value: map of pair of variable & value
        unordered_map<string, unordered_map<string, double>> hash;
        
        for(int i = 0; i < values.size(); ++i) {
            hash[equations[i].first][equations[i].second] = values[i];
            hash[equations[i].second][equations[i].first] = 1.0/values[i];
            hash[equations[i].first][equations[i].first] = 1;
            hash[equations[i].second][equations[i].second] = 1;
        }
        
        vector<double> res;
        
        //dfs for each query
        for(auto p : queries) {
            
            
            double value = bfs(hash,p.first,p.second);
            
            res.push_back(value);
        }
        return res;
    }
    
    double bfs( unordered_map< string, unordered_map<string,double> > &hash, string a, string b) {
        queue<pair<string, double>> q;
        unordered_set<string> visited;
        q.push({a, 1.0});
        visited.insert(a);
        
        while(!q.empty()) {
            int n = q.size();
            for(int i = 0; i < n; ++i) {
                pair<string,double> p = q.front();
                if(hash[p.first].count(b) != 0) {
                    return p.second*hash[p.first][b];
                }
                for(auto pp : hash[p.first]) {
                    if(visited.count(pp.first) == 0) {
                        visited.insert(pp.first);
                        q.push({pp.first, p.second * pp.second});
                    }
                }
                q.pop();
            }
        }
        return -1;
    }
};




//UF

class UF {
private:
    vector<int> id;
    vector<int> rank;
    int size;
    unordered_map<int, double> m;
public:
    UF(int n) {
        size = n;
        for(int i = 0; i < n; ++i) {
            id.push_back(i);
            rank.push_back(0);
            m[i] = 1.0;
        }
    }
    
    int find(int a) {
        while(a != id[a]) {
            id[a] = id[id[a]];
            a = id[a];
        }
        return a;
    }
    
    bool isConnected(int a, int b) {
        return find(a) == find(b);
    }
    
    void updateUnion(int i, double v) {
        for(int a = 0; a < id.size(); ++a) {
            // cout << find(a) << endl;
            if(find(a) == i) {
                m[a] *= v;
                // cout << a << " " << m[a] << endl;
            }
        }
    }
    
    void connect(int a, int b, double v) {
        int i = find(a);
        int j = find(b);
        double v1 = m[a];
        double v2 = m[b];
        if(i == j)
            return;
        
        if(rank[i] < rank[j]) {
            
            if(v == 0) {
                updateUnion(i, 0);
            }
            else 
                updateUnion(i, v2/v1/v);
            id[i] = j;
        }
        else {
            
            if( v == 0)
                updateUnion(j, 0);
            else
                updateUnion(j, v1*v/v2);
            id[j] = i;
            
            if(rank[i] == rank[j])
                rank[i]++;
        }
        
        size--;
        
        // cout << m[a] << " " << m[b] << endl;
    }
    
    double getValue(int a, int b) {
        if(!isConnected(a, b)) {
            return -1;
        }
        else {
            if(m[a] == 0)
                return 0;
            return m[b]/m[a];
        }
    }
    
    
};


//Union Find

class Solution {
public:
    vector<double> calcEquation(vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> queries) {

        int cnt = 0;
        unordered_map<string, int> UFkeys;
        
        for(int i = 0; i < values.size(); ++i) {
            
            if(UFkeys.count(equations[i].first) == 0) {
                UFkeys[equations[i].first] = cnt++;
            }
            
            if(UFkeys.count(equations[i].second) == 0) {
                UFkeys[equations[i].second] = cnt++;
            }
        }
        
        UF uf(cnt);
        
        for(int i = 0; i < values.size(); ++i) {
            int a = UFkeys[equations[i].first];
            int b = UFkeys[equations[i].second];
            uf.connect(a,b, values[i]);
        }
        
        vector<double> res;
        
        //for each query
        for(auto p : queries) {
            
            if(UFkeys.count(p.first) == 0 || UFkeys.count(p.second) == 0) {
                res.push_back(-1);
                continue;
            }
                
            int a = UFkeys[p.first];
            int b = UFkeys[p.second];
            double value = uf.getValue(a, b);
            
            res.push_back(value);
        }
        return res;
    }

};