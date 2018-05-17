class segmentNode{
public:
    int begin, end;
    segmentNode *left = NULL, *right = NULL;
    int sum;
    segmentNode(int begin, int end) {
        this->begin = begin;
        this->end = end;
        sum = 0;
    }
};

class NumArray {
private:
    segmentNode *root;
public:
    NumArray(vector<int> nums) {
        // root = new segmentNode(nums);
        // segmentNode* root = new segmentNode(0, (int)nums.size()-1);
        root = buildTree(nums, 0, (int)nums.size()-1);
        
        // if(root == NULL)
        //     cout << "NULL" << endl;
        // else
        //     cout << root->sum << endl;
        
    }
    
    segmentNode * buildTree(vector<int>& nums, int begin, int end) {
        if(begin > end) {
            return NULL;
        }
        segmentNode* cur = new segmentNode(begin, end);
        if(begin == end) {
            cur->sum = nums[begin];
            // cout << cur->sum << endl;
            return cur;
        }
        int mid = (begin+end)/2;
        cur->left = buildTree(nums, begin, mid);
        cur->right = buildTree(nums,mid+1, end);
        cur->sum = cur->left->sum + cur->right->sum;
        return cur;
    }
    
    void update(int i, int val) {
        update(root, i, val);
    }
    
    void update(segmentNode *cur, int i, int val) {
        if(cur->begin == cur->end)
            cur->sum = val;
        else {
            int mid = (cur->begin + cur->end) / 2;
            if(i <= mid)
                update(cur->left, i, val);
            else
                update(cur->right, i, val);
            cur->sum = cur->left->sum + cur->right->sum;
        }
        
    }
    
    int sumRange(int i, int j) {
        return sumRange(root, i, j);
    }
    
    int sumRange(segmentNode *cur, int i, int j) {
        // if(cur == NULL)
        //     cout << "NULL" << endl;
        // else
        //     cout << cur->sum << endl;
        if(cur->begin == i && cur->end == j)
            return cur->sum;
        int mid = (cur->begin + cur->end) / 2;
        if(j <= mid) {
            return sumRange(cur->left, i, j);
        }
        else if(i > mid) {
            return sumRange(cur->right, i, j);
        }
        else {
            return sumRange(cur->left, i, mid) + sumRange(cur->right, mid+1, j);
        }
    }
};




////Binary Indexed Tree

class NumArray {
private:
    vector<int> bitree;
    vector<int> num;
public:
    NumArray(vector<int> nums) {
        bitree = vector<int>(nums.size()+1, 0);
        num = nums;
        for(int i = 0; i < nums.size(); ++i) {
            update2(i+1, nums[i]);
        }
        
    }
    
    void update(int i, int val) {   
        update2(i+1, val-num[i]);
        num[i] = val;
    }
    
    void update2(int i, int val) {
        while(i < bitree.size()) {
            
            bitree[i] += val;
            i = i + (i & -i);
        }
    }
    
    int sumRange(int i, int j) {
        return sum(j+1) - sum(i);
    }
    
    int sum(int i) {
        int res = 0;
        while(i > 0) {
            res += bitree[i];
            i = i - (i & -i);
        }
        return res;
    }
};


/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * obj.update(i,val);
 * int param_2 = obj.sumRange(i,j);
 */