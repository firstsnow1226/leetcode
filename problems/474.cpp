class Solution {
    static const int MAXN = 105;
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int dp[MAXN][MAXN];
        memset(dp,0,sizeof(dp));
        for(auto str:strs){
            int x = 0;
            int y = 0;
            for(auto ch:str){
                if( ch == '0' )
                    x++;
                else
                    y++;
            }
            for(int i=m;i>=0;i--){
                for(int j=n;j>=0;j--){
                    if( i < x or j < y )
                        continue;
                    dp[i][j] = max(dp[i][j],dp[i-x][j-y]+1);
                }
            }
        }
        return dp[m][n];
    }
};
