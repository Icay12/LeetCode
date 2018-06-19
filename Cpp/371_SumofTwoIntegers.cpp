class Solution {
public:
    int getSum(int a, int b) {
        
        while((a&b)!= 0) {
            int tmpa = a;
            int tmpb = b;
            b = (tmpa & tmpb) << 1;
            a = (tmpa | tmpb) ^ (tmpa & tmpb);
        }
        return a | b;
    }
};


class Solution {
public:
    int getSum(int a, int b) {
        
        while((a&b)!= 0) {
            int tmpa = a;
            int tmpb = b;
            b = (tmpa & tmpb) << 1;
            a = (tmpa ^ tmpb);
        }
        return a | b;
    }
};