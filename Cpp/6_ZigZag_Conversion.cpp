class Solution {
public:
    string convert(string s, int numRows) {
        if(s == "" || s.size() <= numRows || numRows == 1) //necessary
        	return s;

        int length = s.size();
        string result = "";

        for(int i = 1; i <= numRows; ++i) {
        	int pointer = i;
        	int subpointer = 2*numRows - i;

        	while(pointer <= length ) {
        		result += s[pointer-1];
        		if(i != 1 && i != numRows) {
        			if(subpointer > length)
        				break;
        			result += s[subpointer-1];
        			subpointer += 2*numRows - 2;
				}
        		pointer += 2*numRows - 2;
        	
        	}
        }
        return result;

    }
};

/*n=numRows
Δ=2n-2    1                           2n-1                         4n-3
Δ=        2                     2n-2  2n                    4n-4   4n-2			2n-4
Δ=        3               2n-3        2n+1              4n-5       .			2n-6
Δ=        .           .               .               .            .
Δ=        .       n+2                 .           3n               .
Δ=        n-1 n+1                     3n-3    3n-1                 5n-5			2n-2*(n-1)
Δ=2n-2    n                           3n-2                         5n-4
*/
/*

*/