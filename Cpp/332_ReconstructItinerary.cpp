class Solution {
public:
    
    unordered_map<string, multiset<string>> imap;
    vector<string> res;
    
    vector<string> findItinerary(vector<pair<string, string>> tickets) {
        
        for(auto ticket : tickets) {
            imap[ticket.first].insert(ticket.second);
        }
        rec("JFK");
        reverse(res.begin(), res.end());
        return res;
    }
    
    void rec(string depart) {
        while(imap[depart].size() != 0) {
            string next = *imap[depart].begin();
            imap[depart].erase(imap[depart].begin());
            rec(next);
        }
        res.push_back(depart);
    }
};