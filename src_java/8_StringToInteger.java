public class Solution {
    public int myAtoi(String str) {
    	int sign = 1;
    	int theNumber = 0;
    	int begin = 0;
    	if(str.length() == 0) {
    		return 0;
    	}
    	str = str.trim();
    	if(str.charAt(0) == '+' || str.charAt(0) == '-') {
    		sign = str.charAt(0) == '+' ?  1 : -1;
    		begin = 1;
    	}
    	for(int i = begin; i < str.length(); ++i) {
    		int digit = str.charAt(i) - '0';
    		if(digit > 9 || digit < 0) {
    			break;
    		}
    		if(theNumber > Integer.MAX_VALUE/10 || theNumber == Integer.MAX_VALUE/10 && digit > Integer.MAX_VALUE % 10) {
    			if(sign > 0) 
    				return Integer.MAX_VALUE;
    			else
    				return Integer.MIN_VALUE;
    		}
    		theNumber = theNumber * 10 + digit;
    	}
        return theNumber * sign;
    }
}