// Forward declaration of the read4 API.
int read4(char *buf);

class Solution {
private:
    int len4 = 0;
    int ptr4 = 0;
    char buf4[4];
public:
    /**
     * @param buf Destination buffer
     * @param n   Maximum number of characters to read
     * @return    The number of characters read
     */
    int read(char *buf, int n) {
        int i = 0;
        while(i < n){
            if(ptr4 == len4) {
                ptr4 = 0;
                len4 = read4(buf4);
                if(len4 == 0)
                    break;
            }
            buf[i++] = buf4[ptr4++];
        }
        return i;
    }
};
