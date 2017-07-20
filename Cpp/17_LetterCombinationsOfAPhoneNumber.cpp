class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> result;
        if(digits == "") {  //special case, before result.push_back("")
            return result;
        }
        result.push_back(""); //to make sure result.size() != 0
        cout << result.size() <<endl;
        const vector<string> Letter = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        for(int i = 0; i < digits.length(); ++i) {
            string iStr = Letter[digits[i]-'0'];
            if(iStr == "") {
                continue;
            }
            vector<string> tmp;
            for(int i = 0; i < iStr.length(); ++i) {
                for(int j = 0; j < result.size(); ++j) {
                    tmp.push_back(result[j]+iStr[i]);
                }
            }
            result.swap(tmp);
        }

        return result;

    }
};