class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        int begin = 0;
        int len = 0;
        vector<string> res;
        for(int i = 0; i < words.size(); ++i) {
            //enough length for a line, words[i] do not count
            if(len + words[i].length() + (i - begin) > maxWidth) {             
                int spaceLen = i - 1 - begin == 0? maxWidth-len : (maxWidth - len) / (i - 1 - begin);
                // cout << spaceLen << endl;
                int extraLen = i - 1 - begin == 0? 0 : (maxWidth - len) % (i - 1 - begin);
                string line = "";
                for(int j = begin; j < i - 1; ++j) {
                    line += words[j] + string( spaceLen+ (extraLen-- > 0), ' ' );
                }
                line += words[i-1];
                //when only one word in a line
                if(line.length() < maxWidth) {
                    line += string(spaceLen, ' ');
                }
                // cout << line << endl;
                res.push_back(line);
                begin = i;
                len = 0;
            }
            
            //need more word
            
            //last line
            if(i == (int)words.size() - 1) {
                string line = "";
                for(int j = begin; j <= i; ++j ) {
                    if(j == begin)
                        line += words[j];
                    else
                        line += " " + words[j];
                }
                int spaceLen = maxWidth - line.length();
                line += string(spaceLen, ' ');
                res.push_back(line);
            }
            
            len += words[i].length();

        }
        return res;
    }
};