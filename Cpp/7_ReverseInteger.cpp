class Solution {
public:
    int reverse(int x) {
        //extreme values in cpp
        //<limits.h>
        //INT_MIN, INT_MAX

        //just use longlong~. smart!
        long long result = 0;
        while(x != 0) {
        	result = result * 10 + x % 10;
        	x /= 10;
        	if(result > INT_MAX || result < INT_MIN) {
        		result = 0;
        		break;
        	}
        }
        return result;
    }
};