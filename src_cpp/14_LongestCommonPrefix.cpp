#include<iostream>
#include<vector>
#include<string>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
		string prefix = "";
		//if not, there will be runtime error
		if(strs.size() == 0 || strs[0].size() == 0)
		    return prefix;
		for(int i=0; i < strs[0].size(); ++i) {
			char c = strs[0][i];
			for(int j=1; j < strs.size(); ++j) {
				if(i > strs[j].size()-1 || strs[j][i] != c)
					return prefix;
			}
			prefix  = prefix + c;
		}
		return prefix;
    }
};

int main() {
	string s1 = "ab";
	string s2 = "abcd";
	string s3 = "abc";
	vector<string> strs;
	strs.push_back(s1);
	strs.push_back(s2);
	strs.push_back(s3);
	Solution* So = new Solution();
	string prefix = So->longestCommonPrefix(strs);
	cout << prefix <<endl;
}