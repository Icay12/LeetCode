#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <cmath>
#include <stack>
using namespace std;


class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int len = matrix.size();
        for(int i = 0; i < len / 2; ++i) {
            for(int j = i; j < len-1-i; ++j) {
                int k = 4;
                int x = i;
                int y = j;
                int replace = matrix[x][y];
                while(k > 0) {
                    --k;
                    int tmpValue = matrix[y][len-1-x];
                    matrix[y][len-1-x] = replace;
                    replace = tmpValue;
                    int tmpX = x;
                    x = y;
                    y = len-1-tmpX;
                }
            }

        }
    }
};

int main() {

//    vector<vector<int>> nums = {{5,1,9,11},{2,4,8,10},{13,3,6,7},{15,14,12,16}};
    vector<vector<int>> nums = {{1,2,3},{4,5,6},{7,8,9}};
    Solution S;
    string a = "0123456789";
    S.rotate(nums);
    int len = nums.size();
    for(int i = 0; i < len; ++i) {
        for(int j = 0; j < len; ++j) {
            cout << nums[i][j] << " ";
        }
        cout << endl;
    }


    return 0;
}