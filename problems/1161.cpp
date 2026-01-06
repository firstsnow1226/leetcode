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
    static const int MAXN = 10005;
    int sum[MAXN];
    const int INF = -1e9;
public:
    void f(TreeNode* root, int lv){
        if( root == NULL )
            return;
        if( sum[lv] == INF )
            sum[lv] = 0;
        sum[lv] += root->val;
        f(root->left, lv+1);
        f(root->right, lv+1);
    }

    int maxLevelSum(TreeNode* root) {
        for(int i=0;i<MAXN;i++)
            sum[i] = INF;
        f(root,1);
        int ans = 0;
        int ans_sum = INF;
        for(int i=1;i<MAXN;i++){
            if( sum[i] > ans_sum ){
                ans = i;
                ans_sum = sum[i];
            }
        }
        return ans;
    }
};
