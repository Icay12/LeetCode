class Solution {
public:
    vector<int> getRow(int rowIndex) {
        if(rowIndex < 0) {
            vector<int> res;
            return res;
        }
        vector<int> res(rowIndex+1, 1);
        int former = 1;
        for(int i = 0; i <= rowIndex; ++i) {
            for(int j = 0; j <= i; ++j) {
                if(j == 0 || j == i)
                    continue;
                int tmp = former + res[j];
                former = res[j];
                res[j] = tmp;
            }
        }
        return res;
    }
};