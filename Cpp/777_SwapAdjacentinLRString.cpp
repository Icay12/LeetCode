class Solution {
public:

    bool canTransform(string start, string end) {
        int i = 0, j = 0;
        if(start.length() != end.length())
            return false;
        start.push_back('X');
        end.push_back('X');
        int len = start.length();

        while(i < len && j < len) {
            while(i < len && start[i] == 'X') ++i;
            while(j < len && end[j] == 'X') ++j;
            if(i == len && j != len || j == len && i != len)
                return false;
            if(start[i] != end[j])
                return false;
            if(start[i] == 'L' && j > i)
                return false;
            if(start[i] == 'R' && j < i)
                return false;
            ++i,++j;
        }

        return true;
    }
};
