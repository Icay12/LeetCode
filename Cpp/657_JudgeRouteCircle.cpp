class Solution {
public:
    bool judgeCircle(string moves) {
        int disUD = 0;
        int disLR = 0;
        for(auto c : moves) {
            if(c == 'U')
                disUD += 1;
            else if(c == 'D')
                disUD -= 1;
            else if(c == 'L') 
                disLR += 1;
            else
                disLR -= 1;
        }
        return (disUD == 0) && (disLR == 0);
    }
};