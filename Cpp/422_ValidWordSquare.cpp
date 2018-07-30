class Solution {
public:
    bool validWordSquare(vector<string>& words) {
        int m = words.size();
            
        for(int i = 0; i < m; ++i) {
            if(words[i].length() > m)
                return false;
            for(int j = 0; j < words[i].length(); ++j) {
                if( words[j].length() <= i || words[i][j] != words[j][i])
                    return false; 
                
            }
            
        }
        return true;
    }
};