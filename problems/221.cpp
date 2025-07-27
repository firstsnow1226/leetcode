#define MAXN 301
class Solution {
public:
    int row[MAXN][MAXN];
    int col[MAXN][MAXN];
    int dp[MAXN][MAXN];
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        for(int i=0;i<=max(n,m);i++){
            row[i][0] = row[0][i] = col[i][0] = col[0][i] = dp[0][i] = dp[i][0] = 0;
        }
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                row[i][j] = (matrix[i-1][j-1]=='0')? 0:row[i][j-1]+1;
                col[i][j] = (matrix[i-1][j-1]=='0')? 0:col[i-1][j]+1;
            }
        }
        int ans = 0;
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(matrix[i-1][j-1] == '0'){
                    dp[i][j] = 0;
                    continue;
                }
                dp[i][j] = min(dp[i-1][j-1],min(row[i][j-1],col[i-1][j]))+1;
                ans = max(ans,dp[i][j]);
            }
        }
        

        return ans*ans;
    }
};
