/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        unordered_map<int, UndirectedGraphNode *> imap;
        return clone(node, imap);
    }
    UndirectedGraphNode *clone(UndirectedGraphNode *node, unordered_map<int, UndirectedGraphNode *>& imap) {
        if(node == NULL)
            return NULL;
        if(imap.count(node->label)!= 0)
            return imap[node->label];
        UndirectedGraphNode *n = new UndirectedGraphNode(node->label);
        imap[node->label] = n;
        for(UndirectedGraphNode * neighbor : node->neighbors) {
            n->neighbors.push_back(clone(neighbor, imap));
        }
        return n;
    }
    
};