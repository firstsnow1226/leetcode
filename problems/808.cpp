typedef long long int ll;
class Solution {
public:
    static const ll X = 25;
    static const ll MAXN = 1001;
    double dp[MAXN][MAXN];

    double f(int i,int j){
        if(i>=MAXN or j>=MAXN)
            return (double)f(i-4,j)*0.25+f(i-3,j-1)*0.25+f(i-2,j-2)*0.25+f(i-1,j-3)*0.25;
        if( i <= 0 and j <= 0 ) return 0.5;
        if( i <= 0 ) return 1;
        if( j <= 0 ) return 0;
        if( dp[i][j] != -1 )
            return dp[i][j];
        dp[i][j] = (double)f(i-4,j)*0.25+f(i-3,j-1)*0.25+f(i-2,j-2)*0.25+f(i-1,j-3)*0.25;
        return dp[i][j];
    }

    double soupServings(int n) {
        if( n%X == 0 )
            n = n/X;
        else
            n = n/X + 1;
        for(int i=0;i<MAXN;i++){
            for(int j=0;j<MAXN;j++)
                dp[i][j] = -1;
        }
        if(n>200) return 1;
        return f(n,n);
    }
};
