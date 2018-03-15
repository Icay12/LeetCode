class Solution {
public:
    void reverseWords(string &s) {
        
        reverse(s.begin(), s.end());
        int len = s.length();
        int word_begin = 0;

        int word_end = 0;
        
        int word_count = 0;
        int pioneer = 0;
        
        //consecutive ' ' and ' ' in both ends should be avoided
        while(true) {
            while(pioneer < len && s[pioneer] == ' ') pioneer++;
            if(pioneer == len)
                break;
            if(word_count) s[word_end++] = ' ';
            word_begin = word_end;
            while(pioneer < len && s[pioneer] != ' ') s[word_end++] = s[pioneer++];
            reverseWord(s, word_begin, word_end-1);
            word_count++;
        }
        s.resize(word_end);
            
        // while(word_end < len) {
        //     if(s[word_end] == ' ' || word_end == len - 1) {
        //         reverseWord(s, word_begin, word_end - 1);
        //         word_end += 1;
        //         word_begin = word_end;
        //     }
        //     else
        //         word_end += 1;
        // }
    }
    
    
    void reverseWord(string &s, int begin, int end) {
        while(begin < end) {
            char tmp = s[begin];
            s[begin] = s[end];
            s[end] = tmp;
            begin++, end--;
        }
        cout << s.substr(begin, end-begin+1) << endl;
    }
};