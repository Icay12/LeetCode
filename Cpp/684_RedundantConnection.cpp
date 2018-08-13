class UF {
public:
    vector<int> id;
    vector<int> rank;
    int count;
    UF(int n) {
        count = n;
        for(int i = 0 ; i< n; ++i) {
            id.push_back(i);
            rank.push_back(1);
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
        return find(a)==find(b);
        
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
        count--;
    }
};
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        UF uf(edges.size());
        vector<int> res;
        for(auto a : edges) {
            if(uf.isConnected(a[0]-1,a[1]-1)) {
                res.push_back(a[0]);
                res.push_back(a[1]);
                return res;
            }
            uf.connect(a[0]-1,a[1]-1);
        }
    }
};