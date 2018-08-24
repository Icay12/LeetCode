//dfs
class Solution {
public:
    int findCircleNum(vector<vector<int>>& M) {
        vector<bool> visited(M.size(), false);
        int res = 0;
        for(int i = 0; i < M.size(); ++i) {
            if(!visited[i]) {
                res++;
                dfs(M, i, visited);
            }
        }
        return res;
    }
    
    void dfs(vector<vector<int>>& M, int i, vector<bool>& visited) {
        if(visited[i])
            return;
        visited[i] = true;
        for(int j = 0; j < M.size(); ++j) { // can't start from i + 1
            if(i!= j && !visited[j] && M[i][j] == 1)
                dfs(M, j, visited);
        }
        return;
    }
};

//union find
class UF {
private:
    vector<int> id;
    vector<int> rank;
    int cnt;
public:
    UF(int n) {
        cnt = n;
        for(int i = 0; i < n; ++i) {
            id.push_back(i);
            rank.push_back(1);
        }
    }
    
    int getCount() {
        return cnt;
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
    
    void connect(int a, int b) {
        int i = find(a);
        int j = find(b);
        if(i == j)
            return;
        if(rank[i] > rank[j]) {
            id[j] = i;
        }
        else if(rank[i] < rank[j]) {
            id[i] = j;
        }
        else {
            id[j] = i;
            rank[i]++;
        }
        cnt--;
        return;
    }
};
class Solution {
public:
    int findCircleNum(vector<vector<int>>& M) {
        UF uf(M.size());
        for(int i = 0; i < M.size(); ++i) {
            for(int j = i + 1; j < M.size(); ++j) {
                if(!uf.isConnected(i,j) && M[i][j] == 1)
                    uf.connect(i,j);
            }
        }
        return uf.getCount();
    }
};