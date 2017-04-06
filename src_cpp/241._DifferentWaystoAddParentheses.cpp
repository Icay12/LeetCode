#include <iostream>
#include <vector>
#include <string>



using namespace std;

class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        vector<int> resultVec;
		int onlyDigit = 1;
        for(int i=0; i < input.size(); ++i) {
            char c = input[i];
            if(c=='+'||c=='-'||c=='*') {
                onlyDigit = 0;
                vector<int> beforeVec;
                vector<int> afterVec;
                beforeVec = diffWaysToCompute(input.substr(0,i));
                afterVec = diffWaysToCompute(input.substr(i+1));
                // 
                for(int j=0; j < beforeVec.size(); ++j) {
                    for(int k=0; k < afterVec.size(); ++k) {
                    	int result = 0;
                    	if(c == '+') {
                		    result = beforeVec[j] + afterVec[k];
                		}
                		else if(c == '-') {
                		    result = beforeVec[j] - afterVec[k];
                		}
                		else if(c == '*') {
                		    result = beforeVec[j] * afterVec[k];
                		}
                		resultVec.push_back(result);
                    }
                }             
            }
        }
        if(onlyDigit == 1) {
            int result = atoi(input.c_str());
            resultVec.push_back(result);
            return resultVec;
        }
        return resultVec;
    }
};

int main() {
    Solution S;
    vector<int> tryIt = S.diffWaysToCompute("2*3-4*5");
    for(int i = 0; i < tryIt.size(); ++i) {
        cout << tryIt[i] << endl;
    }
    return 0;
}