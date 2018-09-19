class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int total = 0, tank = 0, start = 0;
        
        for(int i = 0; i < gas.size(); ++i) {
            int rest = gas[i] - cost[i];
            total += rest;
            tank += rest;
            if(tank < 0) {
                tank = 0;
                start = i + 1;
            }
        }
        
        return total < 0 ? -1 : start;
    }
};