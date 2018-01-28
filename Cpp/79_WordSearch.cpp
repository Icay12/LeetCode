class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        if(board.size() == 0 || board[0].size() == 0) {
            return false;
        }
        vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false));
        for(int i = 0; i < board.size(); ++i) {
            for(int j = 0; j < board[0].size(); ++j) {
                
                if(isExist(board, visited, word, 0, i, j))
                    return true;
            }
        }
        return false;
    }
    bool isExist(vector<vector<char>>& board, vector<vector<bool>>& visited, string word, int begin, int i, int j) {
        if(begin == word.length())
            return true;
        if(i >= board.size() || i < 0 || j >= board[0].size() || j < 0 || visited[i][j] == true || word[begin] != board[i][j])
            return false;
        visited[i][j] = true;
        if(isExist(board, visited, word, begin+1, i+1, j) || isExist(board, visited, word, begin+1, i, j+1)
               || isExist(board, visited, word, begin+1, i-1, j) || isExist(board, visited, word, begin+1, i, j-1))
            return true;
        visited[i][j] = false;
        return false;
    }
};