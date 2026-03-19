class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int dp[1005][1005];
        int zero[1005][1005];
        int N = grid.size();
        int M = grid[0].size();

        for(int i=0;i<=N;i++){
            for(int j=0;j<=M;j++){
                dp[i][j] = 0;
                zero[i][j] = 0;
            }
        }
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                if( grid[i][j] == '.' ){
                    zero[i+1][j+1] = 1;
                    dp[i+1][j+1] = 0;
                }
                if( grid[i][j] == 'X' )
                    dp[i+1][j+1] = 1;
                if( grid[i][j] == 'Y' )
                    dp[i+1][j+1] = -1;
            }
        }
        int ans = 0;
        for(int i=1;i<=N;i++){
            for(int j=1;j<=M;j++){
                dp[i][j] += dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1];
                zero[i][j] += zero[i-1][j]+zero[i][j-1]-zero[i-1][j-1];
                if( dp[i][j] == 0 and zero[i][j] != i*j )
                    ans++;
                
            }
        }

       return ans;

    }
};
