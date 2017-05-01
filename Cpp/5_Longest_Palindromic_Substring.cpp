class Solution {
public:
    string longestPalindrome(string s) {
        if(s.size() == 0)
        	return "";
        if(s.size() == 1)
        	return s;

        int length = s.size();

        int center = 0;
        int maxlen = 1;
        int begin = 0;
        for( ; center <  length - 1; ) {
        	if(length - center <= maxlen / 2)
        		break;

        	int i, j;
        	i = j = center;
        	while(s[j+1] == s[j]) {
        		j = j + 1;
        	}
        	center = j + 1;
        	while(i > 0 && j < length-1 && s[i-1] == s[j+1]) {
        		i = i - 1;
        		j = j + 1;
        	}

        	if(j - i + 1 > maxlen) {
        		maxlen = j - i + 1;
        		begin = i;
        	}
        	
        }
        return s.substr(begin, maxlen);
    }
};

