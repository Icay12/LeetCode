class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int len = digits.size();
        int p = 0;
        for(int i = len-1; i >= 0; --i) {
            if(digits[i] == 9)
                digits[i] = 0;
            else {
                digits[i] += 1;
                return digits;
            }
        }
        digits[0] = 1;
        digits.push_back(0);
        return digits;
    }
};