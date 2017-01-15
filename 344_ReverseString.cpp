#include <iostream>
#include <string>
using namespace std;


class Solution {
public:
    string reverseString(string s) {
        int length = s.size();
        int i = 0;
        int j = length-1;
        while(i < j) {
            char first = s[i];
            char second = s[j];
            s[i] = second;
			s[j] = first;
			++i, --j;
        }
        return s;
    }
};

int main() {
    Solution S;
    string s = "hello";
    cout << S.reverseString(s) <<endl;
}