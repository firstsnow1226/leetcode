/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    int maxdeep = 0;
    int maxval = 0;
    TreeNode* ans;
public:
    void find_maxdeep(TreeNode* now, int d){
        if( now == NULL )
            return;
        maxdeep = max(maxdeep, d);
        find_maxdeep(now->left, d+1);
        find_maxdeep(now->right, d+1);
    }
    int f(TreeNode* now, int d){
        if( now == NULL )
            return 0;
        int val = f(now->left, d+1) + f(now->right, d+1);
        if( d == maxdeep )
            val += 1;
        if( val > maxval ){
            ans = now;
            maxval = val;
        }
        return val;
    }

    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        find_maxdeep(root, 0);
        f(root, 0);
        return ans;
    }
};
