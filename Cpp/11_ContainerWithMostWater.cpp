#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxwater = 0, water = 0;
        int i = 0, j = height.size()-1;
        while(i < j) {
            water = (j - i) * min(height[i], height[j]);
            maxwater = maxwater > water ? maxwater : water;
            if(height[i] < height[j]) {
                i++;
            }
            else if(height[i] > height[j]) {
                j--;
            }
            else {
                i++;
                j--;
            }

        }
        return maxwater;
    }
};

int main() {
    Solution S;
    vector<int> height;
    height.push_back(1);
    height.push_back(3);
    height.push_back(2);
    height.push_back(5);
    height.push_back(25);
    height.push_back(24);
    height.push_back(5);
    cout << S.maxArea(height) << endl;
    return 0;
}