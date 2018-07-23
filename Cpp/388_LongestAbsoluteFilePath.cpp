class Solution {
public:
    int lengthLongestPath(string input) {
        int res = 0;
        int currentLevel = 0;
        map<int, int> levels; // maps level and length
        input.push_back('\n');
        
        int currentWord = 0;
        bool isFile = false;
        //iterate input
        for(int i = 0; i < input.length(); ++i) {
            if(input[i] == '\n') {
                levels[currentLevel] = currentWord;
                if(isFile) {
                    res = max(res, currentWord+currentLevel);
                    isFile = false;
                }
                currentLevel = 0;
                currentWord = 0;
            }
            else if(input[i] == '\t') {
                map<int,int>::iterator it = next(levels.begin(),currentLevel); 
                currentWord = it->second;
                currentLevel++;
            }
            else if(input[i] == '.') {
                isFile = true;
                currentWord++;
            }
            else {
                currentWord++;
            }
        }
        return res;
    }
};