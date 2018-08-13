

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
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        unordered_map<int,int> parent;
        vector<int> res;
        vector<int> candidate1;
        vector<int> candidate2;
        int twoParent = -1;
        for(int i = 0; i < edges.size(); ++i) {
            vector<int> a = edges[i];
            if(parent.count(a[1]) != 0) {
                candidate2 = a;
                candidate1.push_back(parent[a[1]]);
                candidate1.push_back(a[1]);
                twoParent = i;
                break;
            }
            parent[a[1]] = a[0];
                
        }
        UF uf(edges.size());
        // cout << twoParent << endl;
        for(int i = 0; i < edges.size(); ++i) {
            if( twoParent == -1) {
                vector<int> a = edges[i];
                if(uf.isConnected(a[0]-1,a[1]-1)) {
                    res.push_back(a[0]);
                    res.push_back(a[1]);
                    return res;
                }
                uf.connect(a[0]-1,a[1]-1);
            }
            else {
                if(i == twoParent)
                    continue;
                vector<int> a = edges[i];
                if(uf.isConnected(a[0]-1,a[1]-1)) {
                    return candidate1;
                }
                uf.connect(a[0]-1,a[1]-1);
            }
            
        }
        return candidate2;
    }
};
