#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int start = 0; //Mark the start position of substrings
        vector<int> character(256,-1);
        int maxlen = 0;
        for(int i = 0; i < s.size(); ++i) {
			if(character[s[i]] >= start) { //repeat characters
				start = character[s[i]] + 1; // critical step, wrong to set start = i

			}
			maxlen = maxlen > i-start+1 ? maxlen : i-start+1;
			character[s[i]] = i;
        }
        return maxlen;
    }
};

int main() {
    Solution S;
    string str = "abcdabcefabc";//"abcbabcdeef";
    int len = S.lengthOfLongestSubstring(str);
    cout << len << endl;
}