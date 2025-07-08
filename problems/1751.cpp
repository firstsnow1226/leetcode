vector<long> num;
vector<vector<long>> dp;
class Solution {
public:
    int maxValue(vector<vector<int>>& events, int k) {
        num.clear();
        dp.clear();
        int L = events.size();
        for(auto x:events){
            num.push_back(x[0]);
            num.push_back(x[1]);
        }
        sort(num.begin(),num.end());
        num.erase(unique(num.begin(),num.end()),num.end());

        sort(events.begin(), events.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });

        int m = num.size();
        
        dp.resize(m+1);
        for(int i=0;i<=m;i++){
            for(int j=0;j<=k;j++)
                dp[i].push_back(0);
        }
        int now = 1;
        for(int i=0;i<L;i++){
            int org_s = events[i][0];
            int org_e = events[i][1];
            int s = lower_bound(num.begin(),num.end(),org_s)-num.begin()+1;
            int e = lower_bound(num.begin(),num.end(),org_e)-num.begin()+1;

            for (; now <= e; now++) {
                for (int j = 0; j <= k; ++j) {
                    dp[now][j] = max(dp[now][j], dp[now - 1][j]);
                }
            }

            for(int j=1;j<=k;j++){
                dp[e][j] = max(dp[e][j],dp[s-1][j-1]+events[i][2]);
            }
        }

        long ans = 0;
        for(int i=0;i<=m;i++){
            for(int j=0;j<=k;j++){ 
                ans = max(ans,dp[i][j]);
            }
        }

        return ans;
    }
};
