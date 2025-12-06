typedef long long int ll;
class Solution {
    const ll MOD = 1e9+7;
    static const ll MAXN = 5e4+5;
    ll dp[MAXN];
    ll prs[MAXN];
public:
    int countPartitions(vector<int>& nums, int k) {
        int N = nums.size();
        for(int i=0;i<=N;i++){
            dp[i] = 0;
            prs[i] = 0;
        }
        multiset<ll> st;
        dp[0] = prs[0] = 1;
        int L = 0;
        for(int i=0;i<N;i++){
            st.emplace(nums[i]);
            while( L <= i and *st.rbegin()-*st.begin() > k ){
                st.erase(st.find(nums[L]));
                L++;
            }
            dp[i+1] = (prs[i] - ((L > 0)? prs[L-1]: 0) + MOD) % MOD;
            prs[i+1] = (prs[i] + dp[i+1]) % MOD;
        }
        return dp[N];
    }
};
