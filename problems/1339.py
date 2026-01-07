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
    long sum;
    long ans;
    static const long MOD = 1e9+7;
    void get_sum(TreeNode* now){
        if( now == NULL )
            return;
        sum += now->val;
        get_sum(now->left);
        get_sum(now->right);
    }
    long f(TreeNode* now){
        if( now == NULL )
            return 0;
        long tot = now->val;
        tot += f(now->left);
        tot += f(now->right);
        ans = max(ans, tot*(sum-tot) );
        return tot;
    }
public:
    int maxProduct(TreeNode* root) {
        sum = ans = 0;
        get_sum(root);
        f(root);
        ans %= MOD;
        return (int)ans;
    }
};
