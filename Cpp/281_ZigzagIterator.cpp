class ZigzagIterator {
    list<int> li;
public:
    ZigzagIterator(vector<int>& v1, vector<int>& v2) {
        int n1 = v1.size();
        int n2 = v2.size();
        int maxn = max(n1,n2);
        for(int i = 0; i < maxn; ++i) {
            if(n1 != 0) {
                li.push_back(v1[i]);
                n1--;
            }
            if(n2 != 0) {
                li.push_back(v2[i]);
                n2--;
            }      
        }
    }

    int next() {
        int res = li.front();
        li.pop_front();
        return res;
    }

    bool hasNext() {
        if(li.size() == 0)
            return false;
        return true;
    }
};

/**
 * Your ZigzagIterator object will be instantiated and called as such:
 * ZigzagIterator i(v1, v2);
 * while (i.hasNext()) cout << i.next();
 */