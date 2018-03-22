class Solution {
public:
    bool isSelfCrossing(vector<int>& x) {
        for(int i = 3; i < x.size(); ++i) {
            //i cross i-3
            if(x[i-1] <= x[i-3] && x[i] >= x[i-2]) {cout << "3" << endl;return true;}
            //i cross i-4
            if(i >= 4 && x[i-3] == x[i-1] && x[i-2] > x[i-4] && x[i]+x[i-4]>=x[i-2] )  {cout << "4" << endl;return true;}
            //i cross i-5
            if(i >= 5 && x[i-2] > x[i-4] && x[i-1] < x[i-3]&& x[i-1]+x[i-5] >= x[i-3] && x[i]+x[i-4] >= x[i-2])  {cout << "5"<<i<< endl;return true;}

        }
        return false;
    }
};