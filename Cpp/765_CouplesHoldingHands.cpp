//greedy

class Solution {
public:
    int minSwapsCouples(vector<int>& row) {
        vector<int> pos(row.size());
        for(int i = 0; i < row.size(); ++i) {
            pos[row[i]] = i;
        }
        int res = 0;
        for(int i = 0; i < row.size(); i+=2) {
            //find couple
            int j = row[i]%2 == 0? row[i]+1 : row[i]-1;
            if(row[i+1] != j) {
                int tmp = row[i+1];
                row[i+1] = j;
                row[pos[j]] = tmp;
                pos[tmp] = pos[j];
                pos[j] = i+1;
                res++;
            }
        }
        return res;
        
    }
};


//Union Find

class UF {
    vector<int> id;
    vector<int> rank;
    int count;
public:

    UF(int n) {
        count = n;
        for(int i = 0; i < n; ++i) {
            id.push_back(i);
            rank.push_back(0);
        }
    }
    
    int getCount() {
        return count;
    }
    
    int find(int a) {
        while(a != id[a]) {
            id[a] = id[id[a]];
            a = id[a];
        }
        return a;
    }
    
    void connect(int i, int j) {
        int a = find(i);
        int b = find(j);
        if(a == b)
            return;
        if(rank[a] > rank[b]) {
            id[b] = a;
        }
        else if(rank[a] < rank[b]) {
            id[a] = b;
        }
        else {
            id[b] = a;
            rank[a]++;
        }
        count--;
    }
};

class Solution {
public:
    int minSwapsCouples(vector<int>& row) {
        UF uf(row.size()/2);
        for(int i = 0; i < row.size(); i+=2) {
            uf.connect(row[i]/2, row[i+1]/2);
        }

        return row.size()/2 - uf.getCount();
    }
};