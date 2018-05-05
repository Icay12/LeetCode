class UF {
private:
    int *id;
    int *rank;
    int *len;
    int count;
    int elements;
public:
    UF(int N) {
        count = N;
        elements = N;
        id = new int[N];
        rank = new int[N];
        len = new int[N];
        for(int i = 0; i < N; ++i) {
            id[i] = i;
            rank[i] = 0;
            len[i] = 1;
        }
    }
    
    ~UF() {
        delete [] id;
        delete [] rank;
        delete [] len;
    }
    
    int getCount() {
        return count;
    }
    
    int find(int p) {
        while(p != id[p]) {
            id[p] = id[id[p]];
            p = id[p];
        }
        return p;
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
            len[i] += len[j];
        }
        else if(rank[j] > rank[i]) {
            id[i] = j;
            len[j] += len[i];
        }
        else {
            id[i] = j;
            rank[j]++;
            len[j] += len[i];
        }
        count--;
    }
    
    int findMaxLen() {
        int maxLen = 0;
        for(int i = 0; i < elements; ++i) {
            if(id[i] == i && len[i] > maxLen) {
                maxLen = len[i];
            }
        }
        return maxLen;
    }
    
    
};

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0)
            return 0;
        
        UF uf((int)nums.size());
        unordered_map<int, int> visited;
        for(int i = 0; i < nums.size(); ++i) {
            if(visited.count(nums[i]) != 0) {
                continue;
            }
            visited[nums[i]] = i;
            if(visited.count(nums[i]+1) != 0) {
                uf.connect(visited[nums[i]], visited[nums[i]+1]);
            }
            if(visited.count(nums[i]-1) != 0) {
                uf.connect(visited[nums[i]], visited[nums[i]-1]);
            }
        }
        
        int res = uf.findMaxLen();
        cout << res << endl;
        return res;
            
    }
};