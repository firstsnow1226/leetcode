class Solution {
public:
    static const int MAXN = 1005;
    static const int INF = -1e6;
    int dp[MAXN][MAXN];
    int maxCollectedFruits(vector<vector<int>>& fruits) {
        for(int i=0;i<MAXN;i++){
            for(int j=0;j<MAXN;j++)
                dp[i][j] = INF;
        }
        int N = fruits.size();
        dp[N-1][0] = fruits[N-1][0];
        dp[0][N-1] = fruits[0][N-1];

        for(int j=1;j<N-1;j++){
            for(int i=j+1;i<N;i++){
                dp[i][j] = max(max(dp[i-1][j-1],dp[i][j-1]),dp[i+1][j-1]) + fruits[i][j];
            }
        }
        for(int i=1;i<N-1;i++){
            for(int j=i+1;j<N;j++){
                dp[i][j] = max(max(dp[i-1][j-1],dp[i-1][j]),dp[i-1][j+1]) + fruits[i][j];
            }
        }
        int cnt = 0;
        for(int i=0;i<N;i++)
            cnt += fruits[i][i];

        return dp[N-1][N-2] + dp[N-2][N-1] + cnt;
    }
};
