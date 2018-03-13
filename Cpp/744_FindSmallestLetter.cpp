//simple linear scan
class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        for(char c : letters) {
            if(target < c)
                return c;
        }
        return letters[0];
        
    }
};


//using upper_bound
class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        auto it = upper_bound(letters.begin(),letters.end(), target);
        return it == letters.end() ? letters.front() : *it;
        
    }
};

// O(log(n))
class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        if(target >= letters.back())
            return letters.front();
        int begin = 0, end = letters.size()-1;
        while(begin < end) {
            int mid = (begin + end) / 2;
            if(target < letters[mid])
                end = mid;
            else
                begin = mid + 1;
                
        }
        return letters[begin];
        
    }
};