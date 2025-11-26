typedef long long int ll;
const ll MOD = 1000000007;
const ll MAXN = 50005;
const ll MAXK = 50;
ll dp[MAXN][2][MAXK];
class Solution { 
public:
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        memset(dp, 0, sizeof(dp));
        ll offset = k*100;

        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if( i == 0 and j == 0 ){
                    dp[0][0][grid[i][j]%k] = 1;
                    continue;
                }
                for(int s=0;s<k;s++){
                    dp[j][i%2][s] = 0;
                    if( j != 0 )
                        dp[j][i%2][s] += dp[j-1][i%2][(s+offset-grid[i][j])%k];
                    dp[j][i%2][s] += dp[j][(i+1)%2][(s+offset-grid[i][j])%k];
                    dp[j][i%2][s] %= MOD;
                }
            }
        }
        return dp[grid[0].size()-1][(grid.size()-1)%2][0];
    }
};
