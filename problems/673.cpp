class Solution {
public:
    static const int MAXN = 2005;
    int dp[MAXN]; // dp[i] max len of first i nums
    int cnt[MAXN];
    

    int findNumberOfLIS(vector<int>& nums) {
        dp[0] = 1;
        cnt[0] = 1;
        int maxLen = 1;
        int ans = 0;

        for(int i=1;i<nums.size();i++){
            dp[i] = 1;
            cnt[i] = 1;

            for(int j=0;j<i;j++){
                if( nums[j] < nums[i] ){
                    if( dp[j] + 1 > dp[i] ){
                        dp[i] = dp[j] + 1;
                        cnt[i] = cnt[j];
                    }
                    else if( dp[j] + 1 == dp[i] ){
                        cnt[i] += cnt[j];
                    }
                }
                
            }
            maxLen = max(maxLen,dp[i]);
        }
        for(int i=0;i<nums.size();i++){
            if( dp[i] == maxLen )
                ans += cnt[i];
        }

        return ans;
    }
};
