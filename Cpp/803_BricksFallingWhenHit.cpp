class UF {
public:
    int* id = NULL;
    int* rank = NULL;
    int* cnt = NULL;

    
    UF(int mn, int n) {
        id = new int[mn];
        rank = new int[mn];
        cnt = new int[mn];
        for(int i = 0; i < mn; ++i) {
            id[i] = i;
            rank[i] = 0;
            cnt[i] = 1;
        }
    }
    
    ~UF() {
        delete [] id;
        delete [] rank;
        delete [] cnt;
    }
    
    int find(int a) {
        while(id[a] != a) {
            id[a] = id[id[a]];
            a = id[a];
        }
        return a;
    }
    
    int getSize(int a) {
        return cnt[find(a)];
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
            cnt[i] += cnt[j];
            cnt[j] = 1;
        }
        else if(rank[i] < rank[j]) {
            id[i] = j;
            cnt[j] += cnt[i];
            cnt[i] = 1;
        }
        else {
            id[j] = i;
            rank[i]++;
            cnt[i] += cnt[j];
            cnt[j] = 1;
        }
            
    }
};

class Solution {
public:
    vector<int> hitBricks(vector<vector<int>>& grid, vector<vector<int>>& hits) {
        int m = grid.size();
        int n = grid[0].size();
        
        UF uf(m*n+1, n);
        
        vector<vector<int>> newGrid = grid;

        for(int h = (int)hits.size() - 1; h >= 0; --h) {
            int i = hits[h][0];
            int j = hits[h][1];
            newGrid[i][j] = 0;
        }
        
        //connect the top bricks to the dummy node mn
        for(int i = 0; i < n; ++i) {
            if(newGrid[0][i] == 1)
                uf.connect(i, m*n);
        }

//         cout << uf.getSize(m*n) << endl;
        //connect the other bricks
        for(int i = 1; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                //compare up
                if(i != 0 && newGrid[i][j] == 1 && newGrid[i-1][j] == 1) {
                    uf.connect(i*n+j, (i-1)*n+j);
                }
                
                //compare left
                if(j != 0 && newGrid[i][j] == 1 && newGrid[i][j-1] == 1) {
                    uf.connect(i*n+j, i*n+j-1);
                }
            }
        }

        vector<int> res;
        
        for(int h = (int)hits.size() - 1; h >= 0; --h) {
            int i = hits[h][0];
            int j = hits[h][1];
            
            if(grid[i][j] == 0)
                res.push_back(0);
            else {
                int prevStable = uf.getSize(m*n);
                
                if(i != 0 && newGrid[i-1][j] == 1)
                    uf.connect(i*n+j, (i-1)*n+j);
                if(i != m-1 && newGrid[i+1][j] == 1)
                    uf.connect(i*n+j, (i+1)*n+j);
                if(j != 0 && newGrid[i][j-1] == 1)
                    uf.connect(i*n+j, i*n+j-1);
                if(j != n-1 && newGrid[i][j+1] == 1)
                    uf.connect(i*n+j, i*n+j+1);
                if(i == 0)
                    uf.connect(i*n+j, m*n);
                
                int curStable = uf.getSize(m*n);

                if(uf.isConnected(i*n+j, m*n)) {
                    res.push_back(curStable - prevStable - 1);
                    
                }
                else
                    res.push_back(curStable - prevStable);
                newGrid[i][j] = 1;
                
            }
            
        }

        reverse(res.begin(), res.end());

        return res;
        
    }
};

