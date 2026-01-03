class Solution {
    const int MOD = 1e9 + 7;
    static const int MAXN = 5005;
    string s[12] = {"RYR", "RYG", "RGR", "RGY", "YRY", "YRG", "YGR", "YGY", "GRY", "GRG", "GYR", "GYG"};
    int match[12][12];
public:
    int numOfWays(int n) {
        for(int i=0;i<12;i++){
            for(int j=0;j<12;j++){
                if( s[i][0] == s[j][0] or s[i][1] == s[j][1] or s[i][2] == s[j][2] )
                    match[i][j] = 0;
                else
                    match[i][j] = 1;
            }
        }
        int dp[MAXN][12];
        for(int i=0;i<12;i++)
            dp[0][i] = 1;
        for(int r=1;r<n;r++){
            for(int i=0;i<12;i++){
                dp[r][i] = 0;
                for(int j=0;j<12;j++){
                    dp[r][i] += dp[r-1][j] * match[i][j];
                    dp[r][i] %= MOD; 
                }
            }
        }
        int ans = 0;
        for(int i=0;i<12;i++){
            ans += dp[n-1][i];
            ans %= MOD;
        }
        return ans;
    }
};
