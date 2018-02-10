class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> res;
        for(int i = 0; i <= num; ++i) {
            int cnt = 0;
            int a = i;
            while(a > 0) {
                cnt += a & 1;
                a = a >> 1;
            }
            res.push_back(cnt);
        }
        return res;
    }
};


class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> res(num+1,0);

        for(int i = 1; i <= num; ++i) {
            res[i] = res[i& (i-1)] + 1;
        }
        return res;
    }
};