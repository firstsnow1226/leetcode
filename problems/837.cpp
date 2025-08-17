class Solution {
public:
    double new21Game(int n, int k, int maxPts) {
        if( k == 0 )
            return 1;
        if( k + maxPts <= n)
            return 1;
        double dp[10005] = {0.0};
        double sum = 1.0;
        double ans = 0.0;
        dp[0] = 1.0;
        for(int i=1;i<=n;i++){
            dp[i] = sum / maxPts;
            if( i < k ){
                sum += dp[i];
            }
            else{
                ans += dp[i];
            }
            if( i - maxPts >= 0 ){
                sum -= dp[i-maxPts];
            }

        }
        return ans;
    }
};
