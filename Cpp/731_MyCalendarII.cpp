// O(n)

class MyCalendarTwo {
    map<int,int> events;
public:
    MyCalendarTwo() {
        
    }
    
    bool book(int start, int end) {
        events[start]++;
        events[end]--;
        //check the validility
        int b = 0;
        for(auto p : events) {
            b += p.second;
            if(b >= 3) {
                events[start]--;
                events[end]++;
                return false;
            }
                
        }
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo obj = new MyCalendarTwo();
 * bool param_1 = obj.book(start,end);
 */



///BST

class Node {
public:
    int begin;
    int end;
    int count;
    Node* left;
    Node* right;
    Node(int b, int e) {
        begin = b;
        end = e;
        left = NULL;
        right = NULL;
        count = 1;
    }
    
};

class BST {
private:
    Node* iroot;
public:
    BST () {
        iroot = NULL;
    }
    bool insert(Node* node) {
        // if(iroot != NULL)
        //     cout << iroot->count << endl;
        if(check(iroot, node)) {
            insertHelper(iroot, node);
            return true;
        }
        else
            return false;
    }
    
    bool check(Node* root, Node* node) {
        if(root == NULL)
            return true;
        if(node->end <= root->begin) {
            return check(root->left, node);
        }
        else if(node->begin >= root->end) {
            return check(root->right, node);
        }
        else {
            if(root->count == 2)
                return false;
            if(node->begin == root->begin && node->end == root->end) {
                return true;
            }
            else if(node->begin == root->begin) {
                int rbegin = min(root->end, node->end);
                int rend = max(root->end, node->end);
                Node* newRight = new Node(rbegin, rend);
                if(rend == root->end)
                    newRight->count = root->count;
                
                return check(root->right, newRight);
            }
            else if(node->end == root->end) {
                int lbegin = min(root->begin, node->begin);
                int lend = max(root->begin, node->begin);
                Node* newLeft = new Node(lbegin, lend);
                if(lbegin == root->begin)
                    newLeft->count = root->count;

                return check(root->left, newLeft);
            }
            else {
                int lbegin = min(root->begin, node->begin);
                int rend = max(root->end, node->end);
                int lend = max(root->begin, node->begin);
                int rbegin = min(root->end, node->end);
                
                Node* newRight = new Node(rbegin, rend);
                Node* newLeft = new Node(lbegin, lend);
                if(lbegin == root->begin)
                    newLeft->count = newLeft->count;
                if(rend == root->end)
                    newRight->count = root->count;

                return check(root->left, newLeft) && check(root->right, newRight);
            }
        }
    }
        
    
    void insertHelper(Node* &root, Node* node) {
        if(root == NULL) {
            root = node;
            return;
        }
        if(node->end <= root->begin) {
            insertHelper(root->left, node);
        }
        else if(node->begin >= root->end) {
            insertHelper(root->right, node);
        }
        else {
            // if(root->count == 2)
            //     return false;
            
            if(node->begin == root->begin && node->end == root->end) {
                root->count++;
                return;
            }
            else if(node->begin == root->begin) {
                int rbegin = min(root->end, node->end);
                int rend = max(root->end, node->end);
                Node* newRight = new Node(rbegin, rend);
                if(rend == root->end)
                    newRight->count = root->count;
                root->end = rbegin;
                root->count++;
                
                insertHelper(root->right, newRight);

            }
            else if(node->end == root->end) {
                int lbegin = min(root->begin, node->begin);
                int lend = max(root->begin, node->begin);
                Node* newLeft = new Node(lbegin, lend);
                if(lbegin == root->begin)
                    newLeft->count = root->count;
                root->begin = lend;
                root->count++;
                insertHelper(root->left, newLeft);
            }
            else {
                int lbegin = min(root->begin, node->begin);
                int rend = max(root->end, node->end);
                int lend = max(root->begin, node->begin);
                int rbegin = min(root->end, node->end);
                
                Node* newRight = new Node(rbegin, rend);
                if(lbegin == root->begin)
                    node->count = root->count;
                if(rend == root->end)
                    newRight->count = root->count;
                root->end = rbegin;
                root->begin = lend;
                
                node->end = lend;
                node->begin = lbegin;
                
                root->count++;
                insertHelper(root->left, node);
                insertHelper(root->right, newRight);
            }
            
            
        
        }
    }
};

class MyCalendarTwo {
    BST* root;
public:
    MyCalendarTwo() {
        root = new BST();
    }
    
    bool book(int start, int end) {
        // cout << "b" << endl;
        Node* a = new Node(start, end);
        return root->insert(a);
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo obj = new MyCalendarTwo();
 * bool param_1 = obj.book(start,end);
 */