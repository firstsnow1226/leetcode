class Solution {
    static const int MAXN = 105;
public:
    int minDeletionSize(vector<string>& strs) {
        int L = strs[0].length();
        int N = strs.size();
        int dp[MAXN];
        dp[0] = 1;

        int max_keep = 1;
        for(int i=1;i<L;i++){
            dp[i] = 1;
            for(int j=0;j<i;j++){
                bool find = true;
                for(int k=0;k<N;k++){
                    if( strs[k][j] > strs[k][i] )
                        find = false;
                }
                if( find ){
                    dp[i] = max(dp[i], dp[j]+1);
                }
            }
            max_keep = max(max_keep, dp[i]);
        }
        return L - max_keep;
    }
};
