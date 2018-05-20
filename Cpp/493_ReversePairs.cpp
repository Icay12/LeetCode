
//BIT

class Solution {
public:
    int reversePairs(vector<int>& nums) {
        if(nums.size() == 0)
            return 0;
        vector<int> bit(nums.size() + 1, 0);
        vector<long> ordered_nums(nums.begin(), nums.end()); 
        sort(ordered_nums.begin(), ordered_nums.end());
        int res = 0;
        for(int i = 0; i < nums.size(); ++i) {
            // cout << 2*nums[i] + 1 << endl;
            int index = lower_bound(ordered_nums.begin(), ordered_nums.end(), (long)2*nums[i] + 1) - ordered_nums.begin();
            // cout << 2*nums[i] + 1 << " " <<index << endl;
            res += search(bit,index+1);
            
            int i_index = lower_bound(ordered_nums.begin(), ordered_nums.end(), nums[i]) - ordered_nums.begin();
            insert(bit, i_index+1);
            // cout << i_index << endl;
        }
        
        return res;
    }
    
    int search(vector<int>& bit, int i) {
        int sum = 0;
        while(i < bit.size()) {
            sum += bit[i];
            i += i & (-i);
        }
        return sum;
    }
    
    void insert(vector<int>& bit, int i) {
        while(i > 0) {
            bit[i] += 1;
            // cout << i << " " <<bit[i] << endl;
            i -= i & (-i);
            
        }
    }

    
};


//merge sort

class Solution {
public:
    int reversePairs(vector<int>& nums) {
        return reversePairs(nums, 0, (int)nums.size()-1);
    }
    
    int reversePairs(vector<int>& nums, int l, int r) {
        if(l >= r)
            return 0;
        int res = 0;
        int m = l + ((r - l) >> 1);
        res = reversePairs(nums, l, m) + reversePairs(nums, m+1, r);
        
        vector<int> merge;
        
        int i = l; 
        int p = m + 1;  //cnt pairs
        int j = m + 1;  //merge
        // int k = 0;
        while(i <= m) {
            while(p <= r && nums[i] > (long) 2 * nums[p]) {
                ++p;
            }
            res += p - m - 1;
            while(j <= r && nums[i] >=  nums[j]) {
                merge.push_back(nums[j++]);
            }
            merge.push_back(nums[i++]);
        }
        
        while(j <= r) {
            merge.push_back(nums[j++]);
        }
        
        copy(merge.begin(), merge.end(), nums.begin() + l);
        return res;
        
    }
};

//BST. Time exceed error

class Node{
public:
    int leftcnt, rightcnt;
    int val, cnt;
    Node* left, *right;

    Node(int v) {
        cnt = 1;
        val = v;
        left = NULL;
        right = NULL;
        leftcnt = 0;
        rightcnt = 0;
    }

};

class Solution {

public:
    int reversePairs(vector<int>& nums) {
        if(nums.size() == 0)
            return 0;
        
        vector<int> rnums = nums;
        reverse(rnums.begin(), rnums.end());
        Node* root = new Node(rnums[0]);
        int res = 0;
        for(int i= 1; i < rnums.size(); ++i) {
            res += search(root, rnums[i]);
            insert(root, rnums[i]);
        }
        return res;

    }

    Node* insert(Node* root, int val) {
        if(root == NULL) {
            root = new Node(val);
            return root;
        }
        if(val > root->val) {
            root->right = insert(root->right, val);
            root->rightcnt += 1;
        }
        else if(val < root->val) {
            root->left = insert(root->left, val);
            root->leftcnt += 1;
        }
        else {
            root->cnt += 1;
        }
        return root;
    }

    int search(Node* root,  int val) {
        if(root == NULL)
            return 0;
        if(val - root->val > root->val) {  // if val*2, might exceed INT limit
            return (root->leftcnt + root->cnt) + search(root->right, val);
        }
        else {
            return search(root->left, val);
        }
    }
};
